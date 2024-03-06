#include <iostream>

using namespace std;

class A {
public:
    A() = default;
    A(int val) {
        a = val;
    }
    int a = 5;
};

class B : public A {
public:
    B() {
        c += a;
    }

    B(int val): c(a), A(val)
    {}
    int c = 1;
};

int main()
{
    A a;
    B b(2);

    cout << b.c << endl;

    return 0;
}