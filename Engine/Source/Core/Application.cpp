#include "Application.h"
#include "SmartPointer/CSharedPtr.h"
#include <cstdio>

namespace Coldlight
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		CSharedPtr<GameObject> sharedPtr = CSharedPtr<GameObject>();
		while (true);
	}
}