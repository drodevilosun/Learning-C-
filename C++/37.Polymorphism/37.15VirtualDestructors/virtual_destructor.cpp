#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Animal {
public:
    Animal() = default;
    explicit Animal(string_view descrpition) : mDescription(descrpition) {}
    virtual ~Animal();
private:
    string mDescription;
};

Animal::~Animal() {
    cout << "Animal destructor called\n";
}

class Feline : public Animal {
public:
    Feline() = default;
    Feline(string_view fur_style, string_view description) : mFurStyle(fur_style), Animal(description) 
    {}
    virtual ~Feline();

private:
    string mFurStyle;
};
Feline::~Feline() {
    cout << "Feline destructor called\n";
}

class Dog final : public Feline {
public:
    Dog() = default;
    Dog(string_view fur_style, string_view description) : Feline(fur_style, description) {}
    virtual ~Dog();
};
Dog::~Dog() {
    cout << "Dog destructor called\n";
}

int main() {
    Animal *base = new Dog("Run", "Dog");
    delete base;

    // unique_ptr<Animal> base = make_unique<Dog>("Run", "Dog");
    

    return 0;
}