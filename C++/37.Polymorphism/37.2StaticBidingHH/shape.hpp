#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include <iostream>

class Shape
{
protected:
    std::string_view description;
public:
    Shape() = default;
    Shape(std::string_view des);
    ~Shape();

    void draw() const{
        std::cout << "Shape::draw() called. Drawing " << description << std::endl;
    };

    Shape(const Shape&) = delete;
    Shape& operator=(const Shape&) = delete;
};

#endif