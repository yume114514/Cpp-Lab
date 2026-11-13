#include <iostream>
#include <windows.h>
using namespace std;

class Tree {
private:
    int ages;
public:
    Tree(int a = 0) : ages(a) {}

    void grow(int years) {
        ages += years;
    }

    void age() const {
        cout << "树龄：" << ages << " 年" << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Tree t(5);
    t.age();

    t.grow(3);
    t.age();

    t.grow(10);
    t.age();

    return 0;
}
