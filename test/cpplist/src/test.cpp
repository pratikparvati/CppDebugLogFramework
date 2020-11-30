#include "apply.h"
#include "list.h"
#include "reduce.h"
#include <iostream>

int main() {
    LOG_INIT();
  try {
    int N = 1;
    List olist{};

    for (int i = 0; i < N; ++i) {
      olist.append(i);
    }

    List olist2{};
    olist2 = olist;
    olist2.append(5);
    olist2.deleteAll(0);
    olist2.deleteAll(N);
    olist2.deleteAll(N - 1);
    List list{olist2};

    XDBG << "value(0)=" << list.value(0) << '\n';
    XDBG << "value(1)=" << list.value(1) << '\n';
    XDBG << "value(" << list.length() - 1
              << ")=" << list.value(list.length() - 1) << '\n';
    list = list;
    list.apply(SquareApply{});
    XDBG << "apply^2 & reduce+: " << list.reduce(SumReduce{}) << "\n";
    return 0;
  } catch (const std::exception &e) {
     DLOG(ERROR, "caught exception");
    std::cerr << e.what() << "\n";
    return 1;
  }
}
