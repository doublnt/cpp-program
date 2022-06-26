#include "../include/library.h"

void tsp::test_ptr() {
}

tsp::tsp() {
    cout << "tsp" << "constructor init" << endl;
}

tsp::~tsp() {
    cout << "tsp" << "destructor" << "clear" << endl;
}

t2::t2() {
    //t = std::make_unique<tsp>();
    cout << "t2" << "constructor" << endl;
}

t2::~t2() {
    //t = nullptr;
    cout << "t2" << "destructor" << endl;
}

UseT2::UseT2() {
    local_t2 = std::make_unique<t2>();
}

UseT2::~UseT2() {
    local_t2 = nullptr;
}

