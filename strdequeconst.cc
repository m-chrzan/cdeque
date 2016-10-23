#include <iostream>
#include "strdequeconst.h"

#ifndef NDEBUG
	const static bool debug = true;
#else
	const static bool debug = false;
#endif


unsigned long emptystrdeque() {
    if (debug) {
        std::cerr << "emptystrdeque()" << std::endl;
    }

    static unsigned long id = 0;
    return id;
}
