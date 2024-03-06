#include <string>


enum class PointType {
    cartesian,
    polar
};

class Point {
    Point(float x, float y): x(x), y(y) {}

private:
    // inter class
    class PointFactory {
    public:
        static Point NewCarstian (float x, float y) {
            return Point{x,y};
        }

        static Point NewPolar(float x, float y) {
            return Point(x * 2, y * 2);
        }
    };
    float x, y;
    // friend class PointFactory;
public:
    static PointFactory Factory;
};

// class PointFactory {
// public:
//     static Point NewCarstian (float x, float y) {
//         return Point{x,y};
//     }

//     static Point NewPolar(float x, float y) {
//         return Point(x * 2, y * 2);
//     }
// };

int main()
{
    // Point carstean_obj = PointFactory::NewCarstian(1,1);
    // Point polar_obj = PointFactory::NewPolar(1,1);
    
    // using inner class
    auto carstian = Point::Factory.NewCarstian(2,3);
    
    return 0;
}