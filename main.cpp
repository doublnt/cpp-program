//
// Created by yinxi on 2022/6/20.
//
#include "include/library.h"

std::unique_ptr<UseT2> test_use_t2();

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

    char greeting[] = "Hello";
    std::cout << _mbstrlen(greeting) << std::endl;

    char *p = greeting;
    const char *p1 = greeting;
    char *const p2 = greeting;
    const char *const p3 = greeting;


    std::cout << &p1 << "|" << p1 << std::endl;
    std::cout << &p3 << "|" << p3 << std::endl;
    std::cout << &p2 << "|" << p2 << std::endl;

    const char *const p5 = greeting;
    char const *const p6 = greeting;

    std::vector<char> vec{'1', '2', '4'};
    char ch = 'S';
    auto be = vec.begin();
    *be = 'f';
    //be = &ch;

    auto temp = test_use_t2();
    return 0;
}

std::unique_ptr<UseT2> test_use_t2() {
    auto tt = std::make_unique<UseT2>();

    return tt;
}
