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

#include "dbglog.h"

struct slist {
  int data;
  struct slist *next;
};

void print();
using list_ptr = slist *;

list_ptr head = nullptr;
list_ptr curr = nullptr;

// a->b->c->d->nullptr
void insert(int val) {
  LOG_INIT();
  DLOG(INFO, "Inserting node to linked list");
  VDBG(val);
  list_ptr templist = new slist;
  templist->next = nullptr;
  templist->data = val;
  if (head == nullptr) {
    head = templist;
    curr = head;
  } else {
    curr->next = templist;
    curr = templist;
  }
  // XDBG << print() << std::endl;
}

void free() {
  LOG_INIT();
  list_ptr templist = nullptr;
  while (head != nullptr) {
    templist = head->next;
    XDBG << "Deleted " << head->data << std::endl;
    delete (head);
    head = templist;
  }
  DLOG(INFO, "Memory freed");
}

// d->c->b->a->nullptr
void reverse() {
  LOG_INIT();
  list_ptr next = nullptr;
  list_ptr prev = nullptr;
  while (head != nullptr) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  head = prev;
  DLOG(INFO, "Reversed the linked list");
}

void print() {
  LOG_INIT();
  DLOG(INFO, "======= Linked list ============");
  list_ptr templist = head;

  std::cout << "[head]";
  while (true) {
    if (templist == nullptr)
      break;
    std::cout << "==>" << templist->data << "{@next " << templist->next << "}"
              << "{@curr " << templist << "}" << std::endl;
    templist = templist->next;
  }
  std::cout << "==>[nullptr]" << std::endl;
}

void insert_list(const std::initializer_list<int> &lst) {
  LOG_INIT();
  for (auto &i : lst) {
    VDBG(i);
    insert(i);
  }
}

int main() {
  LOG_INIT();
  std::initializer_list<int> lst = {10, 20, 30, 40, 50, 60};
  insert_list(lst);
  print();
  reverse();
  print();
  free();
  // Test warn message
  DLOG(WARN, "This is a warning message");
  // Test error message
  DLOG(ERROR, "This is a error message");
  return 0;
}
