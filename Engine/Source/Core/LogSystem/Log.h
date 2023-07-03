#pragma once

#include "Core/CoreMinimal.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Coldlight
{
	class CORE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr < spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define CL_CORE_TRACE(...)	::Coldlight::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CL_CORE_INFO(...)	::Coldlight::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CL_CORE_WARN(...)	::Coldlight::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CL_CORE_ERROR(...)	::Coldlight::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CL_CORE_FATAL(...)	::Coldlight::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CL_TRACE(...)	::Coldlight::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CL_INFO(...)	::Coldlight::Log::GetClientLogger()->info(__VA_ARGS__)
#define CL_WARN(...)	::Coldlight::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CL_ERROR(...)	::Coldlight::Log::GetClientLogger()->error(__VA_ARGS__)
#define CL_FATAL(...)	::Coldlight::Log::GetClientLogger()->fatal(__VA_ARGS__)
