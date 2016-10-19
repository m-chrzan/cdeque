#include "strdequeconst.h"

namespace jnp1 {
    unsigned long emptystrdeque() {
        static unsigned long id = 0;
        return id;
    }
}

unsigned long emptystrdeque() {
    return jnp1::emptystrdeque();
}
