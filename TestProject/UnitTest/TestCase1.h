#pragma once

#include "UnitTest/TestCaseBase.h"
#include "Core/SmartPointer/CSharePtr.h"
#include "iostream"
#include "Core/Object/GameObject.h"

using namespace Coldlight;

class TestCase1 : public CTestCaseBase
{
protected:
	virtual bool DoTest() override
	{
		CSharePtr<GameObject> ptr1;
		std::cout << "DoTest" << std::endl;
		return 1 == 1;
	}
};
