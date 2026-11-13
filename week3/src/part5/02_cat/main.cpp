#include <iostream>
#include "Cat.h"

using namespace std;

int main() {
    cout << "程序开始时，猫的数量：" << Cat::getNumOfCats() << "\n";

    Cat a;
    cout << "创建 a 之后：" << Cat::getNumOfCats() << "\n";

    {
        Cat b, c;
        cout << "块内创建 b、c 之后：" << Cat::getNumOfCats() << "\n";

        Cat d = b;
        cout << "拷贝构造 d 之后：" << Cat::getNumOfCats() << "\n";
    }

    cout << "离开块之后：" << Cat::getNumOfCats() << "\n";

    return 0;
}
