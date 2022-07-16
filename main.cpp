//
// Created by yinxi on 2022/6/20.
//
#include <cstring>
#include "include/library.h"

using namespace std;

/*
//std::unique_ptr<UseT2> test_use_t2() {
//    auto tt = std::make_unique<UseT2>();
//
//    return tt;
//}
//
//void test_ptr(const std::shared_ptr<UseT2> &t2_ptr, int priority) {
//
//}
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

   // tt.func_tt(dd2);

    return 0;
}
*/


class TempCon {
public:
    // 构造函数 使用 explicit 是为了避免隐式转换
    explicit TempCon(int d = 100) : data(d) {
        cout << "Create object: " << this << endl;
    }

    // 析构函数
    ~TempCon() {
        cout << "free object: " << this << endl;
    }

    // 赋值函数 其实相当于 TempCon& operator=(TempCon* this, const TempCon &temp)
    // *this 解指针就相当于  TempCon 这个对象
    TempCon &operator=(const TempCon &temp) {
        if (this != &temp) {
            data = temp.data;
        }
        cout << "assign object: " << this << "=" << &temp << endl;
        return *this;
    }

    // 拷贝构造函数
    TempCon(const TempCon &tt) {
        data = tt.data;
        cout << "copy object: " << this << "=" << &tt << endl;
    }

    int get_data() const {
        return data;
    }

    const TempCon *operator&() const {
        return this;
    }

    TempCon *operator&() {
        return this;
    }

private:
    int data;
};

TempCon tes_func(const TempCon &tt) {
    int val = tt.get_data();

    return TempCon(val); // 编译器 优化了， TempCon temp(val)  return temp;
}

//int main() {
//    TempCon tt(200);
//
//    TempCon tt2 = tes_func(tt);
//
//    TempCon *tt_ptr = &tt2;
//}



class CopyTemp {
private:
    char *str;
public:
    explicit CopyTemp(const char *s) {
        if (s != nullptr) {
            str = (char *) malloc(sizeof(char));
            str[0] = '\0';
        } else {
            str = (char *) malloc(sizeof(char) * strlen(s) + 1);
            strcpy(str, s);
        }
    }

    // 拷贝构造函数， 左值未定义的
    explicit CopyTemp(const CopyTemp &temp) {
        str = (char *) malloc(sizeof(char) * strlen(temp.str) + 1);
        strcpy(str, temp.str);
    }

    // 赋值 函数，左值一般都是已经 定义好的。
    CopyTemp &operator=(const CopyTemp &temp) {
        if (this != &temp) {
            free(str);
            str = nullptr;

            str = (char *) malloc(sizeof(char) * strlen(temp.str) + 1);
            strcpy(str, temp.str);
        }

        return *this;
    }

    ~CopyTemp() {
        free(str);
        str = nullptr;
    }
};

//int main() {
//    char *dd = "Hello, world.";
//    CopyTemp copyTemp(dd);
//    CopyTemp copyTemp1(copyTemp);
//
//    CopyTemp copyTemp2("SS");
//    copyTemp2 = copyTemp1;
//}


class Complex {
private:
    int real;
    int vir;

public:
    Complex() : real(0), vir(0) {}

    Complex(int r, int v) {
        real = r;
        vir = v;
    }

    Complex(const Complex &com) {
        real = com.real;
        vir = com.vir;
    }

    void print_complex() const {
        cout << "(" << real << "," << vir << ")" << endl;
    }

    // 不能引用返回的原因是，分配在 栈上的实例， brace 结束后就 析构掉了，返回出去的其实是 野对象
    // 可以这么说。
    Complex operator+(const Complex &complex) const {
        Complex temp(real + complex.real, vir + complex.vir);
        return temp;

//        return {real + complex.real, vir + complex.vir};
    }

//    Complex &operator=(const Complex &com) {
//
//    }

    ~Complex() {
        cout << "free: " << this << endl;
    }
};

//int main() {
//    Complex com;
//    com.print_complex();
//
//    Complex com2(1, 2);
//    com2.print_complex();
//
//    Complex com3(2, 3);
//    com3.print_complex();
//
////    com = com2 + com3;
//    com = com2.operator+(com3);
//}

class Friend {

    friend ostream &operator<<(ostream &ostream1, const Friend &aFriend);

public:
    // 友元 函数 不受 访问权限符号的 控制， 可以放在 private 或者 public 中
    // 作用域不在该 域中
    friend void show(const Friend &aFriend);

    int get_data() const {
        return data;
    }

private:
    int data;
};

void show(const Friend &aFriend) {
    cout << aFriend.data << endl;
}

ostream &operator<<(ostream &ostream1, const Friend &aFriend) {
    ostream1 << "(" << aFriend.data << ")";

    return ostream1;
}

int main() {
    Friend fff{};
    cout << fff << endl;
}

