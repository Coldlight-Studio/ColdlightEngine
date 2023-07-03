#pragma once

#include "Core/Object/GameObject.h"
#include <iostream>


namespace Coldlight
{
	template<typename T>
	class SharedPtr final
	{
	public:
		SharedPtr() : m_Ptr(nullptr), m_refCount(new int(1))
		{
			std::cout << *m_refCount << std::endl;
		}

		//Copy Constructor
		SharedPtr(const SharedPtr& sharedPtr) : m_Ptr(sharedPtr.m_Ptr), m_refCount(sharedPtr.m_refCount)
		{
			++(*m_refCount);
			std::cout << *m_refCount << std::endl;
		}

		~SharedPtr()
		{
			--(*m_refCount);
			std::cout << *m_refCount << std::endl;
			if (*m_refCount == 0)
			{
				delete m_Ptr;
				delete m_refCount;
				std::cout << "Delete Shared_Ptr !"  << std::endl;
			}
		}

		SharedPtr& operator=(SharedPtr& sharedPtr)
		{
			if (this != &sharedPtr) 
			{
				m_Ptr = sharedPtr.m_Ptr;
				(*m_refCount)++;
				std::cout << *m_refCount << std::endl;
			}
			return *this;
		}

	private:
		T* m_Ptr = nullptr;
		int* m_refCount;
	};
}
