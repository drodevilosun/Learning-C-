#include <iostream>
#include "CalculationFactory.hpp"

using namespace std;

int main() {
    CalculationFactory *mFactory = CalculationFactory::get_instance();
    // Create A object
    unique_ptr<Calculation> A_ptr = mFactory->makeCalculation(CalculationType::Sum);
    int sum = A_ptr->calculate(1, 2);
    cout << "Sum result is: " << sum << endl;
    mFactory->print();
    // Create B object
    unique_ptr<Calculation> B_ptr = mFactory->makeCalculation(CalculationType::Multiplication);
    int mul = B_ptr->calculate(2 , 3);
    cout << "Mul result is : " << mul << endl;
    // Create C object
    unique_ptr<Calculation> C_ptr = mFactory->makeCalculation(CalculationType::Other);
    int other = C_ptr->calculate(1, 2);
    cout << "Other result is: " << other << endl;
    
    return 0;
}
