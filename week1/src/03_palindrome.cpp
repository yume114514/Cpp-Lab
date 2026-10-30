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
    long long num;
    cin >> num;
    if(num<0){
        cout <<"NOPE";
    }
    else{
        long long ori=num;
        long long rev=0;
        while (num >0){
            int digit=num%10;
            rev=rev*10+digit;
            num/=10;
        }
        if (ori==rev){
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    return 0;
}
