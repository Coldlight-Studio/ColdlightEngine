#pragma once

#include "../Object/GameObject.h"

namespace Coldlight
{
	template<typename T>
	class CSharedPtr final
	{
	public:
		CSharedPtr() : m_Ptr(nullptr), m_refCount(new int(1))
		{

		}

		//Copy Constructor
		CSharedPtr(const CSharedPtr& sharedPtr) : m_Ptr(sharedPtr.m_Ptr), m_refCount(sharedPtr.m_refCount)
		{
			++(*m_refCount);
		}

		~CSharedPtr()
		{
			--(*m_refCount);
			if (*m_refCount == 0)
			{
				delete m_Ptr;
				delete m_refCount;
			}
		}

		CSharedPtr& operator=(CSharedPtr& sharedPtr)
		{
			if (this != &sharedPtr) 
			{
				m_Ptr = sharedPtr.m_Ptr;
			}
			return *this;
		}

	private:
		T* m_Ptr = nullptr;
		int* m_refCount;
	};
}
