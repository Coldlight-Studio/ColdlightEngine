#pragma once

#include <string>
#include "UnitTestProxy.h"

namespace Coldlight
{
	class CTestCaseBase
	{
	public:
		friend class CUnitTester;

		CTestCaseBase()
		{
			CUnitTestProxy::AddCase(this);
		}

	protected:
		virtual bool DoTest() = 0;
	};
}
