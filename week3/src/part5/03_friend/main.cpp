#include <iostream>
#include "XYZ.h"

using namespace std;

int main() {
    X x(0);
    cout << "初始 i = " << x.getI() << "\n";

    Y y;
    y.g(&x);
    cout << "Y::g 把 i 加 1 后，i = " << x.getI() << "\n";

    Z z;
    z.f(&x);
    cout << "Z::f 把 i 加 5 后，i = " << x.getI() << "\n";

    h(&x);
    cout << "h   把 i 加 10 后，i = " << x.getI() << "\n";

    return 0;
}
