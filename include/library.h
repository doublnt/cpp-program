#ifndef CPP_PROGRAM_LIBRARY_H
#define CPP_PROGRAM_LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class tsp {
public:
    void test_ptr();

    tsp();

    virtual ~tsp();
};

class t2 : tsp {
    //std::unique_ptr<tsp> t;

public:
    t2();

    ~t2();
};

class UseT2{
private:
    std::unique_ptr<t2> local_t2;

public:
    UseT2();
    ~UseT2();
};

#endif //CPP_PROGRAM_LIBRARY_H
