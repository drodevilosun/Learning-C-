// C++ program to illustrate default
// constructor without 'explicit'
// keyword
#include <iostream>
using namespace std;
 
class Complex {
private:
    double real;
    double imag;
 
public:
   
    // Parameterized constructor with default argument
    Complex(double r = 0.0,
            double i = 0.0) : real(r),
                              imag(i)
                              {}
    // no default argument if compare like below in main() will make error
    // Complex(double r,
    //         double i) : real(r),
    //                     imag(i)
    // {
    // }
 
    // A method to compare two
    // Complex numbers
    bool operator == (Complex rhs)
    {
        std::cout << rhs.real << " and " << rhs.imag << std::endl;
        std::cout << real << " and " << imag << std::endl;
        return (real == rhs.real &&
                imag == rhs.imag);
    }
};
 
// Driver Code
int main()
{
    // a Complex object
    Complex com1(3.0, 1.0);
    
    // in C++, if a class has a constructor which can be called with a single argument, then this constructor becomes a conversion constructor because such a constructor allows conversion of the single argument to the class being constructed. In this case, when com1 == 3.0 is called, 3.0 is implicitly converted to Complex type because the default constructor can be called with only 1 argument because both parameters are default arguments and we can choose not to provide them.
    if (com1 == 3.0)
        cout << "Same";
    else
        cout << "Not Same";
    return 0;
}