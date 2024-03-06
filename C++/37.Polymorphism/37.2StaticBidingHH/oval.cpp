#include "oval.hpp"

Oval::Oval(std::string_view des, double m_x, double m_y): 
            Shape(des), m_x_radius(m_x), m_y_radius(m_y)
{}

Oval::~Oval()
{
}
