#include "spdlog/spdlog.h"
#include <core/Logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace core {
    std::shared_ptr<spdlog::logger> Logger::s_logger;

    void Logger::init(LogLevel lvl, bool logToFile) {
        std::vector<spdlog::sink_ptr> sinks;

        sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

        if(logToFile) sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("engine.log", true));

        auto logger = std::make_shared<spdlog::logger>("[ENGINE]", sinks.begin(), sinks.end());
        logger->set_pattern("[%^%l%$] %v");

        switch(lvl) {
            case LogLevel::Trace: logger->set_level(spdlog::level::trace); break;
            case LogLevel::Info:  logger->set_level(spdlog::level::info); break;
            case LogLevel::Warn:  logger->set_level(spdlog::level::warn); break;
            case LogLevel::Error: logger->set_level(spdlog::level::err); break;
            case LogLevel::Off:   logger->set_level(spdlog::level::off); break;
        }
        
        s_logger = logger;
        spdlog::set_default_logger(logger);
    }
}