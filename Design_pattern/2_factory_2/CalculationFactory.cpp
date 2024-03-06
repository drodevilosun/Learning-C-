#include "CalculationFactory.hpp"

CalculationFactory *CalculationFactory::mFactory = nullptr;

unique_ptr<Calculation> CalculationFactory::makeCalculation(CalculationType type) { 
    auto &ptr = mCalculationFactory[type];
    return std::move(ptr);
    // return mCalculationFactory[type];
    // return std::move(&mCalculationFactory[type]);
}

CalculationFactory::CalculationFactory(/* args */)
{
    mCalculationFactory[CalculationType::Sum] = make_unique<A>();
    mCalculationFactory[CalculationType::Multiplication] = make_unique<B>();
    mCalculationFactory[CalculationType::Other] = make_unique<C>();
}

CalculationFactory::~CalculationFactory()
{
}
