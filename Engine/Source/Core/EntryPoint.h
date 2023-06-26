#pragma once

#ifdef CL_PLATFORM_WINDOWS

#include "Application.h"

Coldlight::Application* Coldlight::CreateApplication();

int main(int argc, char** argv)
{
	Coldlight::Log::Init();
	CL_CORE_INFO("Coldlight Engine, version = {0}", "v0.0.1");

	Coldlight::Application* app = Coldlight::CreateApplication();
	app->Run();
	delete app;
}

#endif
