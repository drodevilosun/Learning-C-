#include <iostream>

class Test {
    static int a;
    int b;
    int *c;
};

class Base {
public:
    void func() {
        std::cout << "func() called" << std::endl;
    }
};

class Derived: public Base {
public:
    using Base::func;
    void func(int a) {
        Base::func();
        std::cout << "func(a) called with a: " << a << std::endl;
    }
};

int main() {
    Test test;
    std::cout << "Test size : " << sizeof(test) << std::endl;
    std::cout << "Test* size : " << sizeof(Test*) << std::endl;


    Derived derived;
    derived.func(2);
    derived.func();
    return 0;
}