#pragma once

#include "Application.h"
#include <iostream>
#include <format>

Coldlight::Application* Coldlight::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << std::format("Coldlight Engine, version = {0}", "v0.0.1") << std::endl;

	Coldlight::AutomaticTestFramework::Get().RunAllTests();

	Coldlight::Application* app = Coldlight::CreateApplication();
	app->Run();
	delete app;
}
