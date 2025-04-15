#pragma once

#include "Core/CoreMinimal.h"
#include "AutomaticTestFramework.h"

namespace Coldlight
{
	class CORE_API UnitTest
	{
	public:
		UnitTest(std::string inName) : m_Name(inName)
		{
			AutomaticTestFramework::Get().RegisterTestCase(inName, this);
		}

		virtual bool RunTest() = 0;

		inline const std::string GetName() const
		{
			return m_Name;
		}

	protected:
		std::string m_Name;
	};
}

#define REGISTER_TEST_CASE(Name) \
	Name Name##Case(#Name); \
