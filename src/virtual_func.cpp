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

int main() {
    int ar[] = {10, 20, 30, 40, 50, 60};

    ifstream file;
    file.open("ttt.txt", ios::in | ios::binary);
    if (!file) {
        cerr << "Error open file";
        exit(1);
    }

    for (size_t i = 0; i < sizeof(ar) / sizeof(int); ++i) {
        file >> ar[0];
    }
}

