#ifndef _6S096_CPPLIST_APPLY_H
#define _6S096_CPPLIST_APPLY_H
#include "list.h"

class ApplyFunction {
protected:
  virtual int function(int x) const = 0;

public:
  void apply(List &list) const;
  virtual ~ApplyFunction() {}
};

// An example ApplyFunction (see apply.cpp)
class SquareApply : public ApplyFunction {
  int function(int x) const;
};

#endif // _6S096_CPPLIST_APPLY_H
