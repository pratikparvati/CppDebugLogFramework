#ifndef _6S096_CPPLIST_NODE_H
#define _6S096_CPPLIST_NODE_H
#include "list.h"

class ListNode {
  int _value;
  ListNode *_next;
  ListNode(const ListNode &) = delete;
  ListNode &operator=(const ListNode &) = delete;

public:
  ListNode();
  ListNode(int theValue);
  ~ListNode();
  int &value();
  int value() const;
  ListNode *next();
  void insertAfter(ListNode *before);
  void setNext(ListNode *nextNode);
  static void deleteNext(ListNode *before);
  static void deleteSection(ListNode *before, ListNode *after);

  static ListNode *create(int theValue = 0);
};

#endif // _6S096_CPPLIST_NODE_H
