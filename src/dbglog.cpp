/*
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
 * @file dbglog.c
 * @brief class log implementation
 * @author Pratik Parvati (pratikparvati@gmail.com)
 * @version 1.0
 */

#include "dbglog.hpp"

/**
 * class log constructor
 * @param fname function name
 * @param filename file name
 * @param line line number
 * @return None
 */

log::log(const std::string fname, const std::string filename, unsigned int line)
  : m_fname(fname)
  , m_filename(filename)
{
    std::cout << std::fixed << TIMELOG << RESET << " [" << m_filename << ":"
              << line << "]" << BOLDWHITE << "  --> " << RESET << m_fname
              << std::endl;
}

/**
 * print debug logs
 * @param str print message
 * @param type enum type [DEBUG, INFO, ERROR, WARN]
 * @param line line number
 * @return None
 */

void
log::printDebug(std::string str, typelog type, unsigned int line)
{
    printMutex.lock();
    std::clog << TIMELOG << RESET << " [" << m_filename << ":" << line << "]";
    switch (type) {
        case INFO: {
            std::clog << BLUE << "(INFO) " << RESET << str << std::endl;
            break;
        }
        case ERROR: {
            std::cerr << BOLDRED << "(ERROR) " << RESET << str << std::endl;
            break;
        }
        case WARN: {
            std::cout << YELLOW << "(WARN) " << RESET << str << std::endl;
            break;
        }
        default: {
            std::cout << std::endl;
            break;
        }
    }
    printMutex.unlock();
}

/**
 * class log destructor
 */
log::~log()
{
    std::cout << std::fixed << TIMELOG << RESET << " [" << m_filename << "]"
              << BOLDWHITE << "   <-- " << RESET << m_fname << std::endl;
}