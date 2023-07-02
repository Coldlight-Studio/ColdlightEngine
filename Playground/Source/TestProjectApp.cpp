#include <iostream>

#include "Core/Application.h"
#include "Engine.h"

class TestProject : public Coldlight::Application
{
public:
	TestProject()
	{

	}

	~TestProject()
	{

	}
};

Coldlight::Application* Coldlight::CreateApplication()
{
	return new TestProject();
}
