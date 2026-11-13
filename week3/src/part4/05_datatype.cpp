#include <iostream>
#include <windows.h>
using namespace std;

class DataType {
private:
    enum Kind { CHAR_TYPE, INT_TYPE, DOUBLE_TYPE };
    Kind kind;
    char c;
    int i;
    double d;
public:
    DataType(char v) : kind(CHAR_TYPE), c(v), i(0), d(0) {}
    DataType(int v) : kind(INT_TYPE), c(0), i(v), d(0) {}
    DataType(double v) : kind(DOUBLE_TYPE), c(0), i(0), d(v) {}

    void show() const {
        switch (kind) {
        case CHAR_TYPE:
            cout << "数据类型：char   值：'" << c << "'" << endl;
            break;
        case INT_TYPE:
            cout << "数据类型：int    值：" << i << endl;
            break;
        case DOUBLE_TYPE:
            cout << "数据类型：double 值：" << d << endl;
            break;
        }
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    DataType t1('A');
    DataType t2(65);
    DataType t3(3.14);

    t1.show();
    t2.show();
    t3.show();

    return 0;
}
