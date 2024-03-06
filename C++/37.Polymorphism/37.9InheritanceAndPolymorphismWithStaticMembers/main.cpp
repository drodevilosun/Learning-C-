#include <iostream>

#include "ellipse.h"

void test(const Shape &shape) {
    shape.get_count();
}

int main(){

	//Shape
    Shape shape1("shape1");
    std::cout << "shape count : " << Shape::m_count << std::endl;//1
    
    Shape shape2("shape2");
    std::cout << "shape count : " << Shape::m_count << std::endl;//2
    
    Shape shape3;
    std::cout << "shape count : " << Shape::m_count << std::endl; // 3
    
    std::cout  << "***********************************************" << std::endl;
    
    //Ellipse
    Ellipse ellipse1(10,12,"ellipse1");
    std::cout << "shape count : " << Shape::m_count << std::endl;// 4
    std::cout << "ellipse count : " << Ellipse::m_count << std::endl;//1
    Ellipse::m_count = 10;
    int count = shape1.get_count();
    std::cout << "shape count : " << count << std::endl;// 4


    std::cout  << "***********************************************" << std::endl;

    //Shape polymorphism

    Shape* shapes[] {&shape1,&ellipse1};
    for(auto &s : shapes){
        std::cout << "count : " << s->get_count() << std::endl;
    }

    std::cout  << "***********************************************" << std::endl;
    Shape shapex = ellipse1;
    shapex.get_count();
    test(ellipse1);
    test(shape1);

    Shape &shapet = ellipse1;
    shapet.get_count();
   
    return 0;
}