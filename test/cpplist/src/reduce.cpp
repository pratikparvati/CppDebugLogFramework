#include "reduce.h"
#include "list.h"

int ReduceFunction::reduce(const List &list) const {
  LOG_INIT();
  int result = identity();
  for (auto it = list.begin(); it != list.end(); ++it) {
    result = function(result, *it);
  }
  VDBG(result);
  return result;
}

int SumReduce::function(int x, int y) const {
  LOG_INIT();
  return x + y;
}

int ProductReduce::function(int x, int y) const {
  LOG_INIT();
  return x * y;
}
