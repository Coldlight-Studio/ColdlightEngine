#pragma once

#include "Core/CoreMinimal.h"
#include <string>
#include <map>

namespace Coldlight
{
	class CORE_API AutomaticTestFramework
	{
	public:
		static AutomaticTestFramework& Get()
		{
			static AutomaticTestFramework framework;
			return framework;
		}

		void RegisterTestCase(std::string name, class UnitTest* testCase);

		void RunAllTests();

	private:
		std::map<std::string, class UnitTest*> m_CaseMap;
	};
}
