#pragma once

#include "../Object/GameObject.h"

namespace Coldlight
{
	template<typename T>
	class CSharePtr final
	{
		static_assert(std::is_base_of<GameObject, T>::value, "T can only be GameObject or its subclasses");

	public:
		CSharePtr()
		{

		}

	private:
		T* m_Ptr = nullptr;
	};
}
