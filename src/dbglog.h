/**
 *   Copyright (c) 2020 Pratik Parvati (pratikparvati@gmail.com)

 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file dbglog.h
 * @brief Macros and class for logging framework
 * @author Pratik Parvati (pratikparvati@gmail.com)
 * @version 1.0
 */

#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

/**
 * The enumeration for type of debug logs
 */
enum typelog {
  DEBUG, /**< debug */
  INFO,  /**< info */
  WARN,  /**< warning */
  ERROR  /**< error */
};

/**
 * Debug flag
 * Usage: g++ <file>.cpp -Wall -o <exec> -DDBGFLAG
 */
#ifdef DBGFLAG

/**
 * @defgroup DEBUG_LOG Debug log Macro group
 *
 * @{
 */

/**
 * Initialize log Object;
 * This macro should be used inside every function in the projects to track the
 * function call heirarchy; Usage : void someFunc()
 *          {
 *              LOG_INIT();
 *              ....
 *          }
 *
 *          int main()
 *          {
 *              LOG_INIT();
 *              someFunc();
 *              ....
 *          }
 * should print
 * @35996ns [Log.cpp:138]  --> int main()
 * @64573ns [Log.cpp:128]  --> void someFunc()
 *  ....
 * @256047ns [Log.cpp]   <-- void someFunc()
 * ....
 * @284928ns [Log.cpp]   <-- int main()
 *
 */
#define LOG_INIT() log debug(__PRETTY_FUNCTION__, __FILE__, __LINE__);

/**
 * Macro used to print logs on the debug terminal/console
 * @param type log type (INFO, DEBUG, ERROR, WARN)
 * @param msg  message to print on console
 * Usage:
 *          void someFunc()
 *          {
 *              LOG_INIT();
 *              DLOG(INFO, "info log goes here");
 *              DLOG(ERROR, "error log goes here");
 *              DLOG(WARN, "warning error goes here");
 *          }
 * should print
 * @64573ns [Log.cpp:128]  --> void someFunc()
 * @68895ns [Log.cpp:129](info) info log goes here
 * @110744ns [Log.cpp:130](error) error log goes here
 * @179299ns [Log.cpp:131](warn) warning log goes here
 * @256047ns [Log.cpp]   <-- void someFunc()
 *
 */
#define DLOG(type, msg) debug.printDebug(msg, type, __LINE__)

/**
 * Macro used to print single variable function
 * @param x variable to print on debug terminal/console
 * Usage:
 *       void someFunc()
 *       {
 *          LOG_INIT();
 *          DLOG(INFO, "info log goes here");
 *          DLOG(ERROR, "error log goes here");
 *          DLOG(WARN, "warning log goes here");
 *          std::string str = "Batman";
 *          VDBG(str);
 *       }
 *
 *       int main()
 *       {
 *         LOG_INIT();
 *         someFunc();
 *         int var = 10;
 *         VDBG(var);
 *       }
 * should print
 * @27957ns [Log.cpp:138]  --> int main()
 * @56722ns [Log.cpp:128]  --> void someFunc()
 * @92547ns [Log.cpp:129](info) example info log
 * @196086ns [Log.cpp:130](error) example info error
 * @275469ns [Log.cpp:131](warn) example info error
 * @317409ns [Log.cpp:134](debug) str = Batman
 * @325159ns [Log.cpp]   <-- void someFunc()
 * @337958ns [Log.cpp:143](debug) var = 10
 * @345342ns [Log.cpp]   <-- int main()
 *
 */
#define VDBG(x)                                                                \
  std::cout << GREEN << "@" << std::fixed << TIMELOG << "ns" << RESET << " ["  \
            << __FILE__ << ":" << __LINE__ << "]" << CYAN << "(debug) "        \
            << RESET << #x << " = " << x << std::endl

/**
 * Macro used to print multiple variables with required string
 * Usage:
 *            int var = 10;
 *            int zed = 20;
 *            XDBG << "var = " << var << " zed = " << zed << std::endl;
 * should print
 * @331102ns [Log.cpp:142](debug) var = 10 zed = 20
 *
 */
#define XDBG                                                                   \
  std::cout << GREEN << "@" << std::fixed << TIMELOG << "ns" << RESET << " ["  \
            << __FILE__ << ":" << __LINE__ << "]" << CYAN << "(debug) "        \
            << RESET
/** @} */

#else
/**
 * Dummy macros when DBGFLAG (debug flag) is disbaled
 *
 */
#define LOG_INIT()                                                             \
  do {                                                                         \
  } while (0)
#define DLOG(type, msg)                                                        \
  do {                                                                         \
  } while (0)
#define VDBG(x)                                                                \
  do {                                                                         \
  } while (0)
#define XDBG                                                                   \
  if (0)                                                                       \
  std::cerr

#endif

/**
 * Macro for printing time logs with debug prints
 */
#define TIMELOG                                                                \
  std::chrono::duration_cast<std::chrono::nanoseconds>(                        \
      std::chrono::steady_clock::now() - start)                                \
      .count()

static auto start = std::chrono::steady_clock::now();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

class log {
private:
  std::string m_fname;
  std::string m_filename;

public:
  log(const std::string fname, const std::string filename, unsigned int line);
  void printDebug(std::string str, typelog type, unsigned int line);
  ~log();
};
