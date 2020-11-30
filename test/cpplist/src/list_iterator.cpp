#include "list.h"
#include "list_node.h"

List::iterator::iterator(ListNode *theNode) : _node{theNode} { LOG_INIT(); }
List::iterator &List::iterator::operator++() {
  _node = _node->next();
  return *this;
}
int &List::iterator::operator*() { return _node->value(); }
bool List::iterator::operator==(const iterator &rhs) {
  return _node == rhs._node;
}
bool List::iterator::operator!=(const iterator &rhs) {
  return _node != rhs._node;
}

List::const_iterator::const_iterator(ListNode *theNode) : _node{theNode} {
  LOG_INIT();
}
List::const_iterator &List::const_iterator::operator++() {
  _node = _node->next();
  return *this;
}
const int &List::const_iterator::operator*() {
  LOG_INIT();
  return _node->value();
}
bool List::const_iterator::operator==(const const_iterator &rhs) {
  return _node == rhs._node;
}
bool List::const_iterator::operator!=(const const_iterator &rhs) {
  return _node != rhs._node;
}
