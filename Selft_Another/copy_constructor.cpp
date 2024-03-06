#include <iostream>

class Cake {
public:
    Cake() = default;
    ~Cake();
    Cake(int num_cake);
    void show_num_cake() {
        std::cout << "Number cakes are: " << mNumCake << std::endl;
    }
    Cake(const Cake& other) : mNumCake(other.mNumCake) {
        std::cout << "copy constructor is called" << std::endl;
    }
    Cake& operator=(const Cake& other){
        if (this != &other)
            mNumCake = other.mNumCake;
        std::cout << "copy operator is called" << std::endl;
        (*this).show_num_cake();
        // std::cout <<  << std::endl;
        
        // this is a pointer to current object
        // -> *this is the reference to current object
        // -> return type Cake& -> return *this
        return *this;
    }
    // Cake (const Cake& other) {
    //     mNumCake = other.mNumCake;
    //     std::cout << "copy constructor is call" << std::endl;
    // }

private:
    int mNumCake;
};

Cake::Cake(int num_cake) : mNumCake(num_cake)
{}
Cake::~Cake(){}

// So, to clarify, a reference to an object in C++ is not a container for the entire object or its address; it's a way to access and manipulate the object directly, as if it were a different name for the same thing.
int main()
{
    Cake cakeA(9);
    Cake cakeB = cakeA;
    cakeB.show_num_cake();
    Cake cakeC;
    std::cout << "&cakcC is: " << &cakeC << std::endl;
    cakeC = cakeB;
    cakeC.show_num_cake();
    Cake *cakeD = &cakeC;
    (*cakeD).show_num_cake();
    // (*cakeD) is reference to object the same with cakeC
    cakeD->show_num_cake();
    // std::cout << (*cakeD).show_num_cake() << std::endl;
    return 0;
}
