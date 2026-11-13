#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

const double PI = acos(-1.0);

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void setRadius(double r) { radius = r; }
    double getRadius() const { return radius; }

    double getArea() const {
        return PI * radius * radius;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double r;
    cout << "请输入圆的半径：";
    cin >> r;

    Circle c(r);

    cout << "半径 = " << c.getRadius() << endl;
    cout << "面积 = " << c.getArea() << endl;

    return 0;
}

