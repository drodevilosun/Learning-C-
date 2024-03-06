#include <iostream>
 
class Shape
{
public:
    Shape() = default;
    Shape(std::string_view description) 
        : m_description {description}
    {}
     ~Shape() = default;
    
     virtual void draw() const{
        std::cout << "Shape::draw() called. Drawing " << m_description << std::endl;
    }
 
    virtual void draw(int color_depth) const {
        std::cout << "Shape::Drawing with color depth : " << color_depth << std::endl;
    }
    
protected : 
    std::string m_description{""};
};
//--

class Oval : public Shape
{
public:
    Oval()= default;
    Oval(double x_radius, double y_radius,
                std::string_view description):
                 Shape(description),
                 m_x_radius(x_radius),
                  m_y_radius(y_radius)
                  {}
     ~Oval() = default;
    
    virtual void draw() const override {
        std::cout << "Oval::draw() called. Drawing " << m_description <<
            " with m_x_radius : " << m_x_radius << " and m_y_radius : " << m_y_radius 
                    << std::endl;
    }
 
public:
    double get_x_rad() const{
        return m_x_radius;
    }
    
    double get_y_rad() const{
        return m_y_radius;
    }
 
private : 
    double m_x_radius{0.0};
    double m_y_radius{0.0};
};
//--

class Circle : public Oval
{
public:
    Circle() = default;
    Circle(double radius,std::string_view description)
    : Oval(radius,radius,description)
    {}
     ~Circle() = default;
    
    void draw() const {
        std::cout << "Circle::draw() called. Drawing " << m_description <<
            " with radius : " << get_x_rad() << std::endl;        
    }
    void go_round_and_round()const{
        std::cout << "Circle going round and round" << std::endl;
    } 
    
};
//--

int main(){
   Circle circle1(10, "Tiny circle");
   Shape * p_shape = &circle1;
   p_shape->draw();
   p_shape->draw(20);

   return 0;
}