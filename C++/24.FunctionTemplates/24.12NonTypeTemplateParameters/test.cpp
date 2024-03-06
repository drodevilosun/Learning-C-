#include <iostream>

// func1
/* template<int size, typename T> 
auto find_value(T arr[], T value) 
{
    for (int i{}; i < size; i++) {
        if (arr[i] == value)
            return 1;
    }
    return -1;
} */

// func2
template<typename T> 
auto find_value(T arr[], T value, int size) 
{
    for (int i{}; i < size; i++) {
        if (arr[i] == value)
            return 1;
    }
    return -1;
}

int main() {
    unsigned int ids[] {222333,44556,123555,917666};
    // auto index = find_value<4, unsigned int> (ids, 4455622);
    auto index = find_value<unsigned int>(ids, 4455622, 4);

    std::cout << "index is: " << index << std::endl;
    return 0;
}