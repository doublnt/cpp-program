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

class UseT2 {
private:
    std::unique_ptr<t2> local_t2;

public:
    UseT2();

    ~UseT2();
};

class DataTes {
private:
    int data;

public:
    explicit DataTes(int data_tes) {
        data = data_tes;
    }

    DataTes() {
        data = 200;
        std::cout << "ii" << std::endl;
    }

    DataTes(const DataTes &tes) {
        data = tes.data;
    }

    // 形参 会调用 拷贝构造函数
    void func_tt(DataTes tt) {

    }

    // 返回值时也会调用 拷贝 构造函数
    DataTes func_tt2() {
        DataTes ss;

        return ss;
    }

    // 使用 & 避免形参调用拷贝构造函数
    DataTes &operator=(const DataTes &dataTes) {
        if (this != &dataTes) {
            data = dataTes.data;
        }
        return *this;
    }

    DataTes &test_temp_ref() {
        DataTes ss;

        return ss;
    }
};


#endif //CPP_PROGRAM_LIBRARY_H
