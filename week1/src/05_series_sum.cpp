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
    int n,a;
    cin >>n>>a;
    long long sum=0;
    long long term=0;
    for (int i=1;i<=n;i++){
        term=term*10+a;
        sum=sum+term;
    }
    cout << sum;
    return 0;
}
