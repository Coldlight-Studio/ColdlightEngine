#pragma once

#include <vector>

namespace Coldlight
{
	class CUnitTestProxy final
	{
	public:
		friend class CUnitTester;

		__forceinline static void AddCase(void* inCase)
		{
			m_Cases.push_back(inCase);
		}

	private:
		static std::vector<void*> m_Cases;
	};
}
