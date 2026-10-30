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
    for(int i=100;i<=999;i++){
        int j=i;
        int x=0;
        while (j>0){
            int y=j%10;
            x+=y*y*y;
            j/=10;
        }
        if(x==i){
            cout << i << " ";
        }
    }
    return 0;
}
