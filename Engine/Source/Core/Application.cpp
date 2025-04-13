#include "clpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include <iostream>

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
		WindowResizeEvent e(1280, 720);
		std::cout << e << std::endl;

		while (true);
	}
}