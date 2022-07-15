//
// Created by yinxi on 2022/6/20.
//
#include <cstring>
#include "include/library.h"

std::unique_ptr<UseT2> test_use_t2();

void test_ptr(const std::shared_ptr<UseT2> &ptr, int priority);

int main() {
//    std::string s1{"SSS11"};
//    std::cout << (s1.find_first_not_of("S1") == std::string::npos) << std::endl;
//
//    std::cout << s1.find("1") << std::endl;
//
//    std::vector<std::string> vec{};
//    vec.emplace_back("11");
//    vec.emplace_back("22");
//    vec.emplace_back("11");
//
//    vec.erase(vec.begin() + 0);
//
//    t2 ttt;

//    char greeting[] = "Hello";
//    std::cout << _mbstrlen(greeting) << std::endl;
//
//    char *p = greeting;
//    const char *p1 = greeting;
//    char *const p2 = greeting;
//    const char *const p3 = greeting;
//
//
//    std::cout << &p1 << "|" << p1 << std::endl;
//    std::cout << &p3 << "|" << p3 << std::endl;
//    std::cout << &p2 << "|" << p2 << std::endl;
//
//    const char *const p5 = greeting;
//    char const *const p6 = greeting;
//
//    std::vector<char> vec{'1', '2', '4'};
//    char ch = 'S';
//    auto be = vec.begin();
//    *be = 'f';
//    //be = &ch;
//
//    //auto temp = test_use_t2();
//
//
//    int int_v = 100;
//    int *int_ptr1 = &int_v;
//
//    cout << int_ptr1 << "," << *int_ptr1 << "," << &int_v << endl;
//
//    int *int_ptr2 = int_ptr1; // 指针是指向的对象是同一个，但是指针的地址不一致，拷贝。
//    cout << int_ptr2 << "," << *int_ptr2 << "," << &int_ptr2 << endl;
//
//    std::vector<wchar_t> c{L'；', L';', L'a', L'中', L'；', L'中'};
//
//    for (auto &c_single: c) {
//        if (c_single < 0 || c_single > 255) {
//            //wprintf(to_wstring(c_single).c_str());
//        }
//        std::setlocale(LC_ALL, "en_US.utf8");
//        cout << ispunct(c_single) << "," << iswpunct(c_single) << endl;
//    }
//
//    char *ch_ptr = new char[100];
//    size_t i = 0;
//
//    char *temp = ch_ptr;
//    while (*temp != '\0') {
//        temp++;
//    }
//
//    cout << temp - ch_ptr << endl;
//
//    test_ptr(std::shared_ptr<UseT2>(new UseT2), 100);
//
//    std::shared_ptr<UseT2> t2(new UseT2);
//    test_ptr(t2, 100);
//
//    std::vector<int> vec_in;
//    vec_in.emplace_back(100);
//    vec_in.emplace_back(200);

    DataTes tt{};
    DataTes tt2{20};

    tt = (DataTes) 200; // 竟然调用了 构造函数

    // 初始化 和 赋值 主要观察 等号 左边 是否是已经存在
    DataTes dd = tt; // 初始化

    DataTes dd2;// 赋值
    dd2 = tt;

    tt.func_tt(dd2);

    return 0;
}

std::unique_ptr<UseT2> test_use_t2() {
    auto tt = std::make_unique<UseT2>();

    return tt;
}

void test_ptr(const std::shared_ptr<UseT2> &t2_ptr, int priority) {

}
