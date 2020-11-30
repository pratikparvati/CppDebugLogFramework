#ifndef _6S096_CPPLIST_REDUCE_H
#define _6S096_CPPLIST_REDUCE_H
#include "list.h"

class ReduceFunction {
protected:
  virtual int function(int x, int y) const = 0;

public:
  int reduce(const List &list) const;
  virtual int identity() const = 0;
  virtual ~ReduceFunction() {}
};

// An example ReduceFunction
class SumReduce : public ReduceFunction {
  int function(int x, int y) const;

public:
  SumReduce() {}
  ~SumReduce() {}
  int identity() const { return 0; }
};

// Another ReduceFunction
class ProductReduce : public ReduceFunction {
  int function(int x, int y) const;

public:
  ProductReduce() {}
  ~ProductReduce() {}
  int identity() const { return 1; }
};

#endif // _6S096_CPPLIST_REDUCE_H
