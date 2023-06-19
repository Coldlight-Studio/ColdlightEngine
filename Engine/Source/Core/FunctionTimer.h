#pragma once

#include <iostream>

namespace Coldlight
{
#ifdef _DEBUG
#define TEST_FUC_CYCLE CFunctionTimer timer;
#else
#define TEST_FUC_CYCLE
#endif // _DEBUG

	class CFunctionTimer
	{
	public:
		CFunctionTimer()
		{
			m_StartTime = std::clock();
		}

		~CFunctionTimer()
		{
			std::clock_t endTime = std::clock();
			float duration = static_cast<float>(endTime - m_StartTime) / CLOCKS_PER_SEC * 1000.0f;
			std::cout << "time spanned: " << duration << " ms" << std::endl;
		}

	private:
		std::clock_t m_StartTime;
	};
}
