//
// Created by ae on 19. 07. 2026..
//

#include "Logger/Logger.h"

#include <iostream>
#include <format>
#include <string_view>

static const char* LogLevelToCString(LogLevel InLevel)
{
    switch (InLevel)
    {
        case LogLevel::Info:            return "Info";
        case LogLevel::Warning:         return "Warning";
        case LogLevel::Error:           return "Error";
        case LogLevel::Fatal:           return "FATAL";
        default:                        return "Invalid LogLevel";

    }
}

#if __cplusplus >= 202002L
void Logger::Log(LogLevel InLevel,
    std::string_view InMessage,
    std::source_location const Source)
{
    std::string_view funcSubstr{ Source.function_name() };
    size_t funcIndex = funcSubstr.rfind(' ');
    funcSubstr = funcSubstr.substr(funcIndex + 1);

    std::cout <<
        std::format("[{0}] {1}({2}) => {3} | {4}",
            LogLevelToCString(InLevel),
            Source.file_name(),
            Source.line(),
            funcSubstr,
            InMessage) <<
        std::endl;
}
#elif __cplusplus >= 201703L
void Logger::Log(LogLevel InLevel,
                 std::string_view InMessage,
                 const char* InFuncName,
                 const char* InFile,
                 int InLine)
{
    std::cout << "[" << LogLevelToCString(InLevel) << "] "
        << InFile << "(" << InLine << ")"
        << " => " << InFuncName << "()"
        << " | " << InMessage
        << std::endl;;
}
#else
void Logger::Log(LogLevel InLevel,
                 const std::string& InMessage,
                 const char* InFuncName,
                 const char* InFile,
                 int InLine)
{
    std::cout << "[" << LogLevelToCString(InLevel) << "] "
    << InFile << "(" << InLine << ")"
    << " => " << InFuncName << "()"
    << " | " << InMessage
    << std::endl;;
}
#endif
