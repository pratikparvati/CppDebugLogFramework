#ifndef _INCLUDE_UTILITIES_HPP__
#define _INCLUDE_UTILITIES_HPP__

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>

class Util
{
  private:
    static Util* instance;
    std::mutex timeMutex;
    Util() = default;

  public:
    static Util* getInstance();
    std::string getCurrentTimeandDate();
};

#endif /* _INCLUDE_UTILITIES_HPP__*/
