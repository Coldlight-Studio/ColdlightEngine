#pragma once

#include <string>
#include "../CoreMinimal.h"

namespace Coldlight
{
	enum Flag
	{
		Alive = 1,
		WaitForGC = 1 << 1,
	};

	class GameObject
	{
	public:
		const std::string& GetName() const;

	protected:
		std::string m_Name = "unnamed";
	};
}
