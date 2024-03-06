#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main(){

    // Oval oval1(2.2, 1.2, "Oval1");
    // // Override method make others overload method in based class is not available in dirived class
    // oval1.draw();
    // oval1.draw(22);
    // Get compile error due to draw() is overriden by base class, so other overload of draw() in base class is ignore
    // Circle circle1(3.2, "Circle1");
    // circle1.draw();
    // circle1.draw(33);

    // compiler error because shape pointer won't see virtual function in base class (Shape)
    // Shape * shape_ptr = new Circle(10,"Circle1");
    // shape_ptr->draw(45,"Red");

    // static biding with Oval class
    // Oval * oval_ptr = new Circle(10,"Circle1");
    // oval_ptr->draw(45,"Red");


    Shape * shape_ptr = new Circle(10,"Circle1");
    // Because draw() in shape is virtual, so it's looking for is there any draw() in derived class and use it
    shape_ptr->draw();
    // Because draw(int color_depth) is not virtual, so this is static binding to base class function
    shape_ptr->draw(30);
    

    return 0;
}