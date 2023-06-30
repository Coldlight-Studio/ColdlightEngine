#pragma once

#include "AutomaticTest/UnitTest.h"
#include <string>
using namespace Coldlight;

class TestCase1 : public UnitTest
{
public:
	TestCase1(std::string name) : UnitTest(name)
	{

	}
	
	virtual bool RunTest() override
	{
		return true;
	}
};


REGISTER_TEST_CASE(TestCase1)