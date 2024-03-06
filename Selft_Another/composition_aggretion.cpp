#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    int a = 10;
    static int d;
};

class B {
public:
    A objA;
    ~B() = default;
};

class C {
public:
    vector<A*> list_a;
    vector<A> list_aa;
};

int A::d = 8;

int main() {
    B b;
    C c;
    c.list_a.push_back(&b.objA);
    c.list_aa.push_back(b.objA);
    b.objA.a = 7;
    cout << c.list_a[0]->a << endl;
    b.~B();

    A* ptr_a = c.list_a[0];
    cout << ptr_a->d << endl;
    b.objA.a = 9;

    cout << c.list_a[0]->a << endl;

    cout << c.list_aa[0].a << endl;
    return 0;
}