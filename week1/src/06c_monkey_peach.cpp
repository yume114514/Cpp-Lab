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
int main(){
    int sum=1;
    for(int i=9;i>0;i--){
        sum=(sum+1)*2;
    }
    cout << sum;
    return 0;
}
