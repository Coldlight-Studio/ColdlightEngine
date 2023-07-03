#include "clpch.h"
#include "AutomaticTestFramework.h"
#include "UnitTest.h"
#include "Core/LogSystem/Log.h"

namespace Coldlight
{
	void AutomaticTestFramework::RegisterTestCase(std::string name, UnitTest* testCase)
	{
		auto iterator = m_CaseMap.find(name);
		if (iterator == m_CaseMap.end())
		{
			m_CaseMap.insert(std::make_pair(name, testCase));
		}
	}

	void AutomaticTestFramework::RunAllTests()
	{
		for (auto item : m_CaseMap)
		{
			bool result = item.second->RunTest();
			if (result)
			{
				CL_CORE_INFO("{0} Passed.", item.second->GetName());
			}
			else
			{
				CL_CORE_ERROR("{0} Failed.", item.second->GetName());
			}
		}
	}
}
