//
// Created by yinxi on 2022/7/30.
//
#include <iostream>

using namespace std;

class A {
private:
    int data;

public:
    virtual void show() {
        cout << "A show" << endl;
    }

    A() {

    }

    ~A() {

    }
};

int main() {
    cout << sizeof(A) << endl;
    A a{};
}

