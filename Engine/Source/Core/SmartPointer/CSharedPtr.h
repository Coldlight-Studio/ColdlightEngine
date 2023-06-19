#pragma once

#include "../Object/GameObject.h"

namespace Coldlight
{
	template<typename T>
	class CSharedPtr final
	{
		//static_assert(std::is_base_of<GameObject, T>::value, "T can only be GameObject or its subclasses");

	public:
		CSharedPtr() noexcept : m_Ptr(nullptr) , m_refCount(nullptr)
		{
			
		}

		//Copy Constructor
		CSharedPtr(const CSharedPtr &sharedPtr) : m_Ptr(sharedPtr.m_Ptr), m_refCount(sharedPtr.m_refCount)
		{
			++(*m_refCount);
		}

		~CSharedPtr()
		{
			delete m_Ptr;
			delete m_refCount;
		}
	private:
		T* m_Ptr = nullptr;
		int* m_refCount;
	};
}
