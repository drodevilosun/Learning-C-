#ifndef OVAL_HPP
#define OVAL_HPP
#include "shape.hpp"

class Oval : public Shape
{
protected:
    double m_x_radius{0};
    double m_y_radius{0};
public:
    Oval() = default;
    Oval(std::string_view des, double m_x, double m_y);
    ~Oval();
    void draw() const {
        std::cout << "Oval::draw called. Drawing " << description << 
                    " with m_x_radius : " << m_x_radius << " and m_y_radius : " << m_y_radius 
                    << std::endl;
    }
protected:
    double get_x_rad() const{
        return m_x_radius;
    }
    double get_y_rad() const{
        return m_y_radius;
    }
};
#endif