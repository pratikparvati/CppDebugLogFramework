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

#include "../include/dbglog.h"

void someFunc() {
  LOG_INIT();
  DLOG(INFO, "Inside someFunc()");
  int var = 10;
  char c = '$';
  VDBG(var);
  VDBG(c);
  if (var != c)
    DLOG(WARN, "var != c");
  int d = 0;
  int e = 5;
  if (d == 0) {
    DLOG(ERROR, "Divisor is Zero");
  } else {
    XDBG << "Quotient is " << var / e << std::endl;
  }
}

int main() {
  LOG_INIT();
  DLOG(INFO, "Inside main()");
  someFunc();
  return 0;
}
