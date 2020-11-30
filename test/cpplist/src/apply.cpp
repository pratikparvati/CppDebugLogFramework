#include "apply.h"
#include "list.h"

void ApplyFunction::apply(List &list) const {
  LOG_INIT();
  for (auto it = list.begin(); it != list.end(); ++it) {
    *it = function(*it);
    VDBG(*it);
  }
}

int SquareApply::function(int x) const {
  LOG_INIT();
  return x * x;
}
