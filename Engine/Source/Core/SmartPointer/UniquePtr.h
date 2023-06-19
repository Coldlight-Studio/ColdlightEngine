#pragma once

#include <cstdio>

namespace Coldlight
{
	template <typename T>
	class CUniquePtr 
	{
	public:
		// Default Constructor
		CUniquePtr()
		{
			m_Data = new T();
			printf("CUniquePtr()\n");
		}

		CUniquePtr(CUniquePtr& inPtr)
		{
			m_Data = inPtr.m_Data;
			inPtr.m_Data = nullptr;
		}

		// Copy Assignment
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
	};
}
