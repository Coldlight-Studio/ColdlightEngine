#include <iostream>
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

int main()
{
	TestProject* project = new TestProject();
	project->Run();
	delete project;
	return 0;
}
