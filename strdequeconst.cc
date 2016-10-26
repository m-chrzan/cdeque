#include <iostream>
#include "strdequeconst.h"

namespace {
#ifndef NDEBUG
    const bool debug = true;
#else
    const bool debug = false;
#endif
}

unsigned long emptystrdeque() {
    if (debug) {
        std::cerr << "emptystrdeque()\n";
    }

    return 0;
}
