#include "clpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Core/LogSystem/Log.h"

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
		CL_CORE_TRACE(e);

		while (true);
	}
}