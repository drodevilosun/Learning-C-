#include <iostream>

class Shape {
public:
    Shape() = default;
    ~Shape(){}
    /* way 1 */
    static Shape *obj;
    static Shape& get_instance()
    {
        if (obj == nullptr)
            obj = new Shape();
        return *obj;
    }

    /* way 2 */
    // static Shape *obj;
    // static Shape* get_instance()
    // {
    //     if (obj == nullptr)
    //         obj = new Shape();
    //     return obj;
    // }

    /* way 3 */
    // static Shape obj;
    // static Shape* get_instance()
    // {
    //     return obj;
    // }
    Shape (const Shape& other) = delete;
    Shape &operator=(const Shape& other) = delete;
};

/* way 1-2 */
Shape *Shape::obj = nullptr;
/* way 3 */
// Shape Shape::obj;

int main() {
    /* way 1 */
    Shape *obj1 = (Shape *)&Shape::get_instance();

    /* way 2-3 */
    // Shape *obj1 = Shape::get_instance();


    return 0;
}
