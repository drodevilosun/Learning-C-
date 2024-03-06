#include "exercise.h"
//YOUR CODE WILL GO BELOW THIS LINE
//DON'T MODIFY ANYTHING ABOVE THIS LINE
int Base::m_count = 0;
int Derived::m_count = 0;

Base::Base(int x): m_x(x)
{
    m_count++;
}
Base::~Base() { }
Derived::Derived(int x, int y): Base(x), m_y(y)
{
    m_count++;
}
Derived::~Derived() {}
