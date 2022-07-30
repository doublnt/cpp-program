//
// Created by yinxi on 2022/7/30.
//
#include <iostream>

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

int main() {
    A_Inherit a;
}

