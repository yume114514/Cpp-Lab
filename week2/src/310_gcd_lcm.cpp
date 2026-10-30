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
int gcd(int a,int b){
   while (b != 0) {
        int temp = a % b; 
        a = b;
        b = temp;
    }
    return a;
};
int lcm(int a,int b){
 return a / gcd(a, b) * b;
};
int main(){
    int n,m;
    cin >>n>>m;
    cout << gcd(n,m)<<" "<<lcm(n,m);
    return 0;
}
