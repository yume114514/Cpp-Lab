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
int isprime(int x){
    if (x<=1) return false;
    for (int i =2 ; i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
};
int main(){
    int n;
    cin >>n;
    if (isprime(n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
