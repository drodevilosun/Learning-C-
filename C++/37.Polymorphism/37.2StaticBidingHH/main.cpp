#include "shape.hpp"
#include "oval.hpp"
#include "circle.hpp"

void draw_oval(Oval &oval) {
    oval.draw();
}
void draw_circle(Circle &circle) {
    circle.draw();
}

int main() {
    Shape shape1("Shape1");
    Oval oval1("Oval1", 3.0, 4.0);
    Circle circle1("Circle1", 5.0, 5.0);

    Shape *p_shape = &shape1;
    p_shape->draw();

    // Oval *p_oval = &shape1;
    

    // drawing base oval
    p_shape = &oval1;
    p_shape->draw();

    // drawing base circle
    p_shape = &circle1;
    p_shape->draw();

    draw_oval(oval1);
    draw_circle(circle1);

    return 0;
}