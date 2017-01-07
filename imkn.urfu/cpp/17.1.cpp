#include <iostream>
#include <cmath>
using namespace std;

enum Quarter { first, second, third, fourth, line };

class Point {
	protected:
		double x;
		double y;
	public:
		double distance;

		Point(double x, double y) :
			x(x),
			y(y)
       		{
		}
		Point(istream& stream) {
			stream >> x;
			stream >> y;
		}
		void print() {
			cout << x << ":" << y;
		}
		double distanceTo(Point *anotherPoint) {
			return sqrt(pow(x - anotherPoint->x, 2) + pow(y - anotherPoint->y, 2));
		}
		bool exists() {
			return (x != 0 && y != 0);
		}
		Quarter quarter() {
			if (x > 0 && y > 0) return first;
			if (x < 0 && y > 0) return second;
			if (x < 0 && y < 0) return third;
			if (x > 0 && y < 0) return fourth;
			return line;
		}
};

int main() {
	Point *zeroPoint = new Point(0, 0);
	Point *topPoint = new Point(cin);
	Point *newPoint;
	do {
		newPoint = new Point(cin);
		if (newPoint->quarter() == first
		&& (topPoint->distanceTo(zeroPoint) < newPoint->distanceTo(zeroPoint))){
			delete topPoint;
			topPoint = newPoint;
		}
	} while (newPoint->exists());

	if (topPoint->exists()){
		topPoint->print();
	} else {
		cout << "no points founded\n";
	}

	return 0;
}
