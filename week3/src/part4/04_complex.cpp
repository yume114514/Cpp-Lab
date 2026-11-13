#include <iostream>
#include <windows.h>
using namespace std;

class Complex {
private:
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    void add(const Complex& c) {
        re += c.re;
        im += c.im;
    }

    void show() const {
        cout << re;
        if (im >= 0) cout << "+" << im << "i";
        else cout << im << "i";
        cout << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();

    return 0;
}
