#include "UnitTester.h"
#include "TestCaseBase.h"
#include "UnitTestProxy.h"

namespace Coldlight
{
	void CUnitTester::RunAllCases()
	{
		for (void* caseItem : CUnitTestProxy::m_Cases)
		{
			((CTestCaseBase*)caseItem)->DoTest();
		}
	}
}
