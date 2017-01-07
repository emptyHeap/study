#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point {
	public:

    static float angle(Point a, Point b){
      Point offset = b - a;
      return offset.x ;
    }

		float x;
		float y;

    Point(float x,float y):
      x(x),
      y(y)
    {
    }
    Point(istream& input){
      input >> x >> y;
    }

    Point operator- (const Point R) {
      return *(new Point(x - R.x, y - R.y));
    }

    Point operator+ (const Point R) {
      return *(new Point(x + R.x, y + R.y));
    }

    Point operator* (const float R) {
      return *(new Point(x * R, y * R));
    }

    float angle(Point anotherPoint) {
      return Point::angle(*this, anotherPoint);
    }
};

class Line {
  public:
    Point a;
    Point b;
    Line(Point a, Point b):
      a(a),
      b(b)
    {
    }
};

class Polygon {
  public:

    static vector<Line> edgesFromPoints(vector<Point> points){
      vector<Line> edges;
      for (int i = 0; i < points.size() - 1; i++) {
        edges.push_back(*(new Line(points[i], points[i+1])));
      }
      edges.push_back(*(new Line(points[points.size() - 1], points[0])));
      return edges;
    }

    vector<Point> points;
    vector<Line> edges;

    Polygon(vector<Point> points):
      points(points)
    {
      edges = Polygon::edgesFromPoints(points);
    }
    Polygon(istream& input){
      int pointsAmount;
      input >> pointsAmount;

      for (int i = 0; i < pointsAmount; i++) {
        points.push_back(*(new Point(input)));
      }

      edges = Polygon::edgesFromPoints(points);
    }

    bool contains(Point point) {
      // cout << point.x << ":" << point.y << " check for point\n";
      int intersections = 0;
      for (Line edge : edges) {
        Point a = edge.a;
        Point b = edge.b;

        // cout << a.x << ":" << a.y << " A line point\n";
        // cout << b.x << ":" << b.y << " B line point\n";

        if ((point.x <= a.x || point.x <= b.x) &&
           ((point.y <= a.y && point.y >= b.y) || (point.y >= a.y && point.y <= b.y)))
        {
          Point intersection = a + (b - a) * ((a.y - point.y) / abs(b.y - a.y));
          // cout << intersection.x << ":" << intersection.y << " intersection point\n";

          if (intersection.x >= point.x) intersections += 1;
        }
      }

      return intersections % 2;
    }

    bool contains(Polygon polygon) {
      for (Point point : polygon.points) {
        if (!this->contains(point)) return false;
      }
      return true;
    }

    float area() {
      float area = 0;
      for (Line line : edges) {
        area += line.a.x * line.b.y - line.b.x * line.a.y;
      }
      area /= 2;

      return area;
    }

};

int main(void) {

  int pointsAmount;
  cin >> pointsAmount;

  cout << "enter first polygon (amount of points, then points)\n";
  Polygon *first = new Polygon(cin);

  cout << "enter second polygon the same way as first\n";
  Polygon *second = new Polygon(cin);

  if (second->contains(*first)) {
    cout << "first poly is inside second\n";
    cout << "area difference: " << second->area() - first->area() << "\n";
  } else {
    cout << "first poly is not inside second\n";
  }
}
