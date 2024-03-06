#include <iostream>

template <typename T, typename P>
auto maximum ( T a, P b){
    return (a > b)? a : b;
}

int main(){

    //Largest type is going to be deduced as return type

	auto max1 = maximum<int, double> ('e', 33); // double return type deduced
    std::cout << "max1 : " << max1 << std::endl;
    std::cout << "size of max1 : " << sizeof(max1) << std::endl;

    auto max_test = maximum<char, char> ('e', 33); // double return type deduced
    std::cout << "max_test : " << max_test << std::endl;
    std::cout << "size of max_test : " << sizeof(max_test) << std::endl;

    int a = 33;
    double b = 22.1;
	auto max2 = maximum (a, b); // double return type deduced
    std::cout << "max2 : " << max2 << std::endl;
    std::cout << "size of max2 : " << sizeof(max2) << std::endl;
   
    return 0;
}

