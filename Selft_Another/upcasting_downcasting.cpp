
#include <iostream>

using namespace std;


class A {
public:
  A() = default;
  A(const A & other) {
    cout << "copy constructor\n";
  }
  A &operator=(const A & other) {
    cout << "assignment operator\n";
    return *this;
  }
  virtual void print() {
    cout << "this is A" << endl;
  }
};

class B : public A {
public:
  virtual void print() override {
    cout << "this is B\n";
  }
  void specific_b() {
    cout << "this is specific B\n";
  }
};



int main()
{
  B b_obj;
  // Upcasting
  A*a = &b_obj;
  a->print();
  
  // downcasting
  B *b = dynamic_cast<B*>(a);
  b->specific_b();
  
  
  // downcasting bad design
  A a1;
  B *b1 = dynamic_cast<B*>(&a1);
  
  if(b1 == nullptr)
  {
    cout << "b1 nullptr\n";
  }
  
  b1->print();
  
  return 0;
}



