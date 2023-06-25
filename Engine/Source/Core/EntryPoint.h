#pragma once

#ifdef CL_PLATFORM_WINDOWS

#include "Application.h"

Coldlight::Application* Coldlight::CreateApplication();

int main(int argc, char** argv)
{
	Coldlight::Application* app = Coldlight::CreateApplication();
	app->Run();
	delete app;
}

#endif
