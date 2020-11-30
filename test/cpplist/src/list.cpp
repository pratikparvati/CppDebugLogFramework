#include "list.h"
#include "apply.h"
#include "list_node.h"
#include "reduce.h"

#include <iostream>

List::List() : _length{0}, _begin{nullptr}, _back{nullptr} {}

List::List(const List &list) : _length{0}, _begin{nullptr}, _back{nullptr} {
  LOG_INIT();
  for (auto it = list.begin(); it != list.end(); ++it) {
    VDBG(*it);
    append(*it);
  }
}

List &List::operator=(const List &list) {
  if (this != &list) {
    clear();
    for (auto it = list.begin(); it != list.end(); ++it) {
      append(*it);
    }
  }
  return *this;
}

List::~List() {
  LOG_INIT();
  clear();
}

size_t List::length() const {
  LOG_INIT();
  VDBG(_length);
  return _length;
}

int &List::value(size_t pos) {
  LOG_INIT();
  auto it = begin();
  for (size_t i = 0; i < pos && it != end(); ++it, ++i)
    ;
  if (it == end()) {
    DLOG(ERROR, "List is out of Bound");
    throw ListOutOfBounds();
  }
  return *it;
}

int List::value(size_t pos) const {
  LOG_INIT();
  auto it = begin();
  for (size_t i = 0; i < pos && it != end(); ++it, ++i)
    ;
  if (it == end()) {
    DLOG(ERROR, "List is out of Bound");
    throw ListOutOfBounds();
  }

  return *it;
}

bool List::empty() const {
  LOG_INIT();
  DLOG(INFO, "empty list");
  return _length == 0;
}

List::iterator List::begin() {
  LOG_INIT();
  DLOG(INFO, "beginning of the iterator list");
  return iterator{_begin};
}
List::const_iterator List::begin() const {
  LOG_INIT();
  DLOG(INFO, "beginning of the const iterator list");
  return const_iterator{_begin};
}
List::iterator List::back() {
  LOG_INIT();
  DLOG(INFO, "last element of the iterator list");
  return iterator{_back};
}
List::const_iterator List::back() const {
  LOG_INIT();
  DLOG(INFO, "last element of the const iterator list");
  return const_iterator{_back};
}
List::iterator List::end() {
  LOG_INIT();
  return iterator{nullptr};
}
List::const_iterator List::end() const {
  LOG_INIT();
  return const_iterator{nullptr};
}

void List::append(int theValue) {
  LOG_INIT();
  auto *newNode = ListNode::create(theValue);

  if (empty()) {
    newNode->setNext(_back);
    _begin = newNode;
  } else {
    newNode->insertAfter(_back);
  }

  _back = newNode;
  ++_length;
}

void List::deleteAll(int theValue) {
  LOG_INIT();
  DLOG(WARN, "deleting list elements");
  if (!empty()) {
    // Delete from the front
    while (_begin->value() == theValue && _begin != _back) {
      auto *newBegin = _begin->next();
      delete _begin;
      _begin = newBegin;
      --_length;
    }

    auto *p = _begin;

    if (_begin != _back) {
      // Normal deletion from interior of list
      for (; p->next() != _back;) {
        if (p->next()->value() == theValue) {
          ListNode::deleteNext(p);
          --_length;
        } else {
          p = p->next();
        }
      }

      // Deleting the last item
      if (_back->value() == theValue) {
        ListNode::deleteNext(p);
        _back = p;
        --_length;
      }
    } else if (_begin->value() == theValue) {
      // Deal with the case where we deleted the whole list
      _begin = _back = nullptr;
      _length = 0;
    }
  }
}

List::iterator List::find(iterator s, iterator t, int needle) {
  LOG_INIT();
  XDBG << "finding iterator pointer for " << needle << std::endl;
  for (auto it = s; it != t; ++it) {
    if (*it == needle) {
      return it;
    }
  }
  return t;
}

void List::insert(iterator pos, int theValue) {
  LOG_INIT();
  auto *posPtr = node(pos);
  auto *newNode = ListNode::create(theValue);
  newNode->insertAfter(posPtr);
  ++_length;
}

void List::insertBefore(int theValue, int before) {
  LOG_INIT();
  if (!empty()) {
    if (_begin->value() == before) {
      auto *newNode = ListNode::create(theValue);
      newNode->setNext(_begin);
      _begin = newNode;
      ++_length;
    } else {
      auto *p = _begin;
      for (; p != _back && p->next()->value() != before; p = p->next())
        ;
      if (p != _back && p->next()->value() == before) {
        auto *newNode = ListNode::create(theValue);
        newNode->insertAfter(p);
        ++_length;
      }
    }
  }
}

void List::apply(const ApplyFunction &interface) {
  LOG_INIT();
  interface.apply(*this);
}

int List::reduce(const ReduceFunction &interface) const {
  LOG_INIT();
  return interface.reduce(*this);
}

void List::print() const {
  LOG_INIT();
  std::cout << "{ ";
  for (auto it = begin(); it != back(); ++it) {
    std::cout << *it << " -> ";
  }
  if (!empty()) {
    std::cout << *back() << " ";
  }
  std::cout << "}\n";
}

void List::clear() {
  LOG_INIT();
  DLOG(INFO, "clearing list");
  for (auto *p = _begin; p != nullptr;) {
    auto *p_next = p->next();
    delete p;
    p = p_next;
  }
  _length = 0;
  _begin = nullptr;
  _back = nullptr;
}
