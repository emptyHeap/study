#include "point.h"
#include <cstdlib>

Point::Point()
{
    this->x = (double) rand() / (RAND_MAX) * Point::max;
    this->y = (double) rand() / (RAND_MAX) * Point::max;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Quarter Point::quarter()
{
    if (this->x > 0) {
        if (this->y > 0) {
            return FirstQuarter;
        } else if (this->y < 0) {
            return FourthQuarter;
        } else {
            return CoordLine;
        }
    } else if (this->x < 0) {
        if (this->y > 0) {
            return SecondQuarter;
        } else if (this->y < 0) {
            return ThirdQuarter;
        } else {
            return CoordLine;
        }
    } else {
        return CoordLine;
    }
}

bool Point::simetrical(Point* another) {
    return this->x == -another->x && this->y == another->y;
}

int main()
{
    return 1;
}
