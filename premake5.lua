workspace "ColdlightEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Shipping"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"CL_PLATFORM_WINDOWS",
			"CL_CORE_API_EXPORTS",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Playground")
		}

	filter "configurations:Debug"
		defines "CL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CL_RELEASE"
		optimize "On"
	
	filter "configurations:Shipping"
		defines "CL_SHIPPING"
		optimize "On"

project "Playground"
	location "Playground"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"Engine/Vendor/spdlog/include",
		"Engine/Source"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"CL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CL_RELEASE"
		optimize "On"
	
	filter "configurations:Shipping"
		defines "CL_SHIPPING"
		optimize "On"