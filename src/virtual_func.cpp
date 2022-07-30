//
// Created by yinxi on 2022/7/30.
//
#include <iostream>
#include <fstream>

using namespace std;

class A {
    // 相当于 抽象类了，不能具体实例化。
    virtual void eat() = 0;
};

class A_Inherit : A {
    void eat() override {
        cout << "A_inherit eat" << endl;
    }
};

void print() {
    cout << "err" << endl;
}

int main() {
    // malloc and new operator
    //set_new_handler(print);
    try {
        int *p = new int[400000000000000000];
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
}