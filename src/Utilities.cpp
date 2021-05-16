#include "Utilities.hpp"

Util* Util::instance = 0;

Util*
Util::getInstance()
{
    if (!instance)
        instance = new Util;
    return instance;
}

std::string
Util::getCurrentTimeandDate()
{
    timeMutex.lock();
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    const auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                          now.time_since_epoch()) % 1000;

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << '.'
       << std::setfill('0') << std::setw(3) << now_ms.count();
    timeMutex.unlock();
    return ss.str();
}
