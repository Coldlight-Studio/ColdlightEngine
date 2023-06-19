#pragma once

#include "CoreMinimal.h"

namespace Coldlight
{
	class CORE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

}
