#include <iostream>
#include "point.hpp"

int main(){

    //Print the point count in our program
    //std::cout << "Point count : " << Point::m_point_count << std::endl; //0

    Point p1(10.0,30.1);

    std::cout << "Point count : " << p1.get_point_count() << std::endl; //1

    Point points[] {Point(1,1),Point(),Point(4)};

    std::cout << "Point count : " << p1.get_point_count() << std::endl; //4

    Point p2(p1);
    p2.print_info();
    // std::cout << "Point count : " << p2.print_info() << std::endl; //1

   
    return 0;
}