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
        std::cerr << "emptystrdeque()" << std::endl;
    }

    static unsigned long id = 0;
    return id;
}
