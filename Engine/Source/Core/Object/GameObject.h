#pragma once

#include <string>
#include "Core/CoreMinimal.h"

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
