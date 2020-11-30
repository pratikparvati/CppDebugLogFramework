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

#include "dbglog.h"

/**
 * class log constructor
 * @param fname function name
 * @param filename file name
 * @param line line number
 * @return None
 */

log::log(const std::string fname, const std::string filename, unsigned int line)
    : m_fname(fname), m_filename(filename) {
  std::cout << GREEN << "@" << std::fixed << TIMELOG << "ns" << RESET << " ["
            << m_filename << ":" << line << "]"
            << "  --> " << m_fname << std::endl;
}

/**
 * print debug logs
 * @param str print message
 * @param type enum type [DEBUG, INFO, ERROR, WARN]
 * @param line line number
 * @return None
 */

void log::printDebug(std::string str, typelog type, unsigned int line) {
  std::clog << GREEN << "@" << std::fixed << TIMELOG << "ns" << RESET << " ["
            << m_filename << ":" << line << "]";
  switch (type) {
  case INFO: {
    std::clog << BLUE << "(info) " << RESET << str << std::endl;
    break;
  }
  case ERROR: {
    std::cerr << BOLDRED << "(error) " << RESET << str << std::endl;
    break;
  }
  case WARN: {
    std::cout << YELLOW << "(warn) " << RESET << str << std::endl;
    break;
  }
  default: {
    std::cout << std::endl;
    break;
  }
  }
}

/**
 * class log destructor
 */
log::~log() {
  std::cout << GREEN << "@" << std::fixed << TIMELOG << "ns" << RESET << " ["
            << m_filename << "]"
            << "   <-- " << m_fname << std::endl;
}