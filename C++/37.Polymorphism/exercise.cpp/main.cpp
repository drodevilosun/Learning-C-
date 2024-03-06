#include "exercise.h"

int main()
{
    // Base b1(10);
    // Base b2(20);
    // std::cout << "base count : " << Base::m_count << std::endl;
    // Derived d1(30,40);
    // Derived d2(50,60);
    // std::cout << "base count : " << Base::m_count << std::endl;
    // std::cout << "derived count : " << Derived::m_count << std::endl;

    Base b1(10);
    Base b2(20);
    Derived d1(30,40);
    Derived d2(50,60);
 
    Base * b_ptr1 = &b1;
    Base * b_ptr2 = &d1;
    b_ptr1->print();
    std::cout << "\n";
    b_ptr2->print();
    return 0;
}