#include <iostream>
#include "cstrdequeconst"
#include "cstrdeque"

namespace {
    unsigned long id1 = ::jnp1::emptystrdeque();
    unsigned long id2 = ::jnp1::emptystrdeque();

    int comp = ::jnp1::strdeque_comp(id1, id2);
}

int main() {
    std::cout << comp << std::endl;

    return 0;
}

