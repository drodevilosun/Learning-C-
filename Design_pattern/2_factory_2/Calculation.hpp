#include <iostream>

using namespace std;

class Calculation {
public:
    virtual int calculate(int val1, int val2) = 0;
    virtual ~Calculation() = default;
};

class A: public Calculation {
public:
    virtual int calculate(int val1, int val2) {
        return (val1 + val2);
    }
};

class B: public Calculation {
public:
    virtual int calculate(int val1, int val2) {
        return (val1 * val2);
    }
};

class C: public A {
public:
    virtual int calculate(int val1, int val2) {
        return A::calculate(val1, val2) + 5;
    }
};
