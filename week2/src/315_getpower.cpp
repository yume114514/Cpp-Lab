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
int getPower(int x,int y){
    if(y<0) return 0;
    if(y==0) return 1;    
    if(x==0||x==1) return x;
    return x*getPower(x,y-1);
}
double getPower(double x,int y){
    if(y==0) return 1;
    if (x==0||x==1) return x;
    if(y>0) return x*getPower(x,y-1);
    return 1.0/getPower(x,-y);
}
int main(){
    int a,m;
    double b;
    cin >>a>>b>>m;
    cout<< getPower(a,m)<<' '<<getPower(b,m);
    return 0;
}
