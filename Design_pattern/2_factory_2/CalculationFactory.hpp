#include <iostream>
#include <string>
#include <memory>
#include <map>
#include "Calculation.hpp"

using namespace std;

enum class CalculationType {
    Sum = 0,
    Multiplication,
    Other
};

class CalculationFactory
{
private:
    static CalculationFactory *mFactory;
    map<CalculationType, unique_ptr<Calculation>> mCalculationFactory;
public:
    CalculationFactory();
    ~CalculationFactory();
    static CalculationFactory* get_instance() {
        if (mFactory == nullptr)
            mFactory = new CalculationFactory();
        return mFactory;
    }
    unique_ptr<Calculation> makeCalculation(CalculationType type);
    void print() {
        std::cout << "test smart pointer available after take? \n";
        if(mCalculationFactory[CalculationType::Sum]){
            std::cout << "mCalculationFactory[CalculationType::Sum] : " << mCalculationFactory[CalculationType::Sum]->calculate(1, 2) << std::endl;
        }else{
            std::cout << "mCalculationFactory[CalculationType::Sum] doesn't contain any valid data" << std::endl;
        }
    }


    CalculationFactory(const CalculationFactory& other) = delete;
    CalculationFactory &operator=(const CalculationFactory &other) = delete;
};
