#include <iostream>

template <typename T, unsigned int m_dimension>
class Point {
public:
    Point<T, m_dimension>() {}
    void set_value(int dimension, T value) {
        mValue[dimension] = value;
    }

    T get_value(int dimension) {
        return mValue[dimension];
    }
    void print_info() {
        std::cout << "point : [ ";
        for (int i{0}; i < m_dimension; i++) {
            std::cout << mValue[i] << ' ';
        }
        std::cout << "]";
    }
private:
    T mValue[m_dimension];
};

int main()
{
    Point<double,2> point_2d; // set up a two dimensional point object
    point_2d.set_value(0,10.22); // set up the first component with a double literal
    point_2d.set_value(1,20.11); // set up the second component with a double literal
    point_2d.print_info() ; // print info. should 

    Point<double, 3> point_3d;
    point_3d.set_value(0, 10);
    point_3d.set_value(1, 20);
    point_3d.set_value(2, 30);
    point_3d.print_info();

    return 0;
}