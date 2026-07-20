#include "Logger/Logger.h"

int main()
{

#if __cplusplus >= 202002L

    Logger::Log(LogLevel::Warning, "Logging for C++20 or above");

#else

    LOGGER_LOG(LogLevel::Info, "Logging for C++17 or below");

#endif

    return 0;
}
