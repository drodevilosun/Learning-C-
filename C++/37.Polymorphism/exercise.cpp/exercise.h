#ifndef EXERCISE_H
#define EXERCISE_H
#include <iostream>

//YOUR CODE WILL GO BELOW THIS LINE
//DON'T MODIFY ANYTHING ABOVE THIS LINE
class Base {
public:
    Base() = default;
    Base(int num);
    ~Base();
    static int m_count;
    virtual void print() {
        std::cout << "data[ x :" << m_x << "]" << std::endl;
    }
protected:
    int get_m_x() const {
        return m_x;
    }
private:
    int m_x;
};
class Derived: public Base {
public:
    Derived() = default;
    Derived(int x, int y);
    ~Derived();
    static int m_count;
    void print() {
        std::cout << "data[ x :" << get_m_x() << " y: " << m_y << "]" << std::endl;
    }
private:
    int m_y;
};



//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE
#endif // _EXERCISE_H
