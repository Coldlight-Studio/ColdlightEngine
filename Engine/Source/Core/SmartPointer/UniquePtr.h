#pragma once

#include <cstdio>

namespace Coldlight
{
	template <typename T>
	class UniquePtr final
	{
	public:
		// Default Constructor
		UniquePtr()
		{
			m_Data = new T();
			printf("UniquePtr()\n");

			printf("%p\n", this);
			printf("%p\n", this + 1);
		}

		UniquePtr(UniquePtr& inPtr)
		{

			m_Data = inPtr.m_Data;
			inPtr.m_Data = nullptr;
		}

		// Move Constructor
		UniquePtr& operator=(UniquePtr& inPtr)
		{
			if (this == &inPtr)
			{
				return *this;
			}

			m_Data = inPtr.m_Data;
			inPtr.m_Data = nullptr;
			return *this;
		}

		~UniquePtr() 
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