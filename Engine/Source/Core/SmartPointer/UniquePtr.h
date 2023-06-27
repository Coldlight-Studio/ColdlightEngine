#pragma once

#include <cstdio>

namespace Coldlight
{
	template <typename T>
	class CUniquePtr final
	{
	public:
		// Default Constructor
		CUniquePtr()
		{
			m_Data = new T();
			printf("CUniquePtr()\n");

			printf("%p\n", this);
			printf("%p\n", this + 1);
		}

		CUniquePtr(CUniquePtr& inPtr)
		{

			m_Data = inPtr.m_Data;
			inPtr.m_Data = nullptr;
		}

		// Move Constructor
		CUniquePtr& operator=(CUniquePtr& inPtr)
		{
			if (this == &inPtr)
			{
				return *this;
			}

			m_Data = inPtr.m_Data;
			inPtr.m_Data = nullptr;
			return *this;
		}

		~CUniquePtr() 
		{
			delete m_Data;
		}

		__forceinline T* Get() const
		{
			return m_Data;
		}

	private:
		T* m_Data = nullptr;
		char a[2];
	};
}