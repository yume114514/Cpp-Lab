#include <iostream>
#include <windows.h>
using namespace std;

class CPU {
private:
    unsigned short freq : 12;
    unsigned short wordLen : 1;
    unsigned short cores : 2;
    unsigned short ht : 1;
public:
    CPU(unsigned short f = 3000, unsigned short w = 1,
        unsigned short c = 2, unsigned short h = 1)
        : freq(f), wordLen(w), cores(c), ht(h) {}

    void setFreq(unsigned short f) { freq = f; }
    void setWordLen(unsigned short w) { wordLen = w; }
    void setCores(unsigned short c) { cores = c; }
    void setHyper(unsigned short h) { ht = h; }

    void show() const {
        cout << "时钟频率：" << freq << " MHz" << endl;
        cout << "字长    ：" << (wordLen ? 64 : 32) << " 位" << endl;
        cout << "核数    ：";
        if (cores == 0) cout << "单核";
        else if (cores == 1) cout << "双核";
        else if (cores == 2) cout << "四核";
        else cout << "未定义";
        cout << endl;
        cout << "超线程  ：" << (ht ? "支持" : "不支持") << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    CPU c(3000, 1, 2, 1);
    c.show();

    cout << "sizeof(CPU) = " << sizeof(CPU) << " 字节" << endl;

    return 0;
}

