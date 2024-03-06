
// C++ program to illustrate
// default constructor with
// 'explicit' keyword
#include <iostream>
using namespace std;
 
class Complex {
private:
    double real;
    double imag;
 
public:
    // Default constructor
    explicit Complex(double r = 0.0,
                     double i = 0.0) :
                     real(r), imag(i)
    {
        std::cout << "Constructor is called" << std::endl;
    }
 
    // A method to compare two
    // Complex numbers
    bool operator == (Complex rhs)
    {
        return (real == rhs.real &&
                imag == rhs.imag);
    }
};
 
// Driver Code
int main()
{
    // a Complex object
    Complex com1(3.0, 0.0);
    // Complex com2(4.0, 2.0);
    
    // official way
    // if (com1 == com2)
    // Or we can typecase double to Complex type to compare
    if (com1 == (Complex)3.0)
        cout << "Same";
    else
        cout << "Not Same";
    return 0;
}