#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <string>
#include <iomanip>
using namespace std;
short int divide(unsigned short int x,unsigned short int y){
    if (y==0){
        return -1;
    }
    else{
        return x/y;
    }
};
int main(){
    unsigned short int a,b;
    cin >> a>>b;
    short int result=divide(a,b);
    cout << result;
    return 0;
}
