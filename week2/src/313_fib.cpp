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
const int N=105;
long long arr[N];
long long def(int x){
    if(x==1||x==2){
        return 1;
    }
    if(arr[x]!=0)
    {
        return arr[x];
    }
arr[x]=def(x-1)+def(x-2);
return arr[x];
};
int main(){
    int n;
    cin >>n;
    cout<<def(n);
    return 0;
}
