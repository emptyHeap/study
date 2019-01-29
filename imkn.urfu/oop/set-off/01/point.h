#include <string>

enum Quarter {
    FirstQuarter,
    SecondQuarter,
    ThirdQuarter,
    FourthQuarter,
    CoordLine
};

class Point
{
    Point();
    Point(double x, double y);

public:
    double x, y;
    Quarter quarter();
    bool simetrical(Point* another);
    bool collinear(Point* another);

    static const double max = 99;
};
