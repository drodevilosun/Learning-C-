#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "oval.hpp"

class Circle : public Oval {
private:
public:
    Circle() = default;
    ~Circle();
    Circle(std::string_view des, double m_x, double m_y);

    void draw() const{
        std::cout << "Circle::draw() called. Drawing " << description <<
            " with m_x_radius : " << get_x_rad() << " and m_y_radius : " << get_y_rad() 
            << std::endl;
    }
};

#endif