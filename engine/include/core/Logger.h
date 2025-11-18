#pragma once
#include <memory>
#include <spdlog/spdlog.h>

namespace core {
    enum class LogLevel {
        Trace,
        Info,
        Warn,
        Error,
        Off
    };

    class Logger {
        public:
            static void init(LogLevel, bool logToFile = false);

            static std::shared_ptr<spdlog::logger>& get() { return s_logger; }
        
        private:
            static std::shared_ptr<spdlog::logger> s_logger;
    };
}

// MACROS
#define LOG_TRACE(...) core::Logger::get()->trace(__VA_ARGS__)
#define LOG_INFO(...) core::Logger::get()->info(__VA_ARGS__)
#define LOG_WARN(...) core::Logger::get()->warn(__VA_ARGS__)
#define LOG_ERROR(...) core::Logger::get()->error(__VA_ARGS__)