#include "list_node.h"

ListNode::ListNode() : _value{0}, _next{nullptr} { LOG_INIT(); }
ListNode::ListNode(int theValue) : _value{theValue}, _next{nullptr} {
  LOG_INIT();
}
ListNode::~ListNode() { LOG_INIT(); }
int &ListNode::value() {
  LOG_INIT();
  return _value;
}
int ListNode::value() const {
  LOG_INIT();
  VDBG(_value);
  return _value;
}
ListNode *ListNode::next() {
  LOG_INIT();
  VDBG(_next);
  return _next;
}

void ListNode::insertAfter(ListNode *before) {
  LOG_INIT();
  _next = before->next();
  VDBG(_next);
  before->_next = this;
}

void ListNode::setNext(ListNode *nextNode) {
  LOG_INIT();
  _next = nextNode;
  VDBG(_next);
}

void ListNode::deleteNext(ListNode *before) {
  LOG_INIT();
  auto *after = before->next()->next();
  delete before->next();
  before->_next = after;
}

void ListNode::deleteSection(ListNode *before, ListNode *after) {
  LOG_INIT();
  auto *deleteFront = before->next();
  while (deleteFront != after) {
    auto *nextDelete = deleteFront->next();
    delete deleteFront;
    deleteFront = nextDelete;
  }
}

ListNode *ListNode::create(int theValue) { return new ListNode{theValue}; }
