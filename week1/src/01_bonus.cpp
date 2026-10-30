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
    double reward;
    int profit;
    cin >>profit;
    if(profit<=100000){
        reward=profit*0.1;
    }
    else {
        if(profit<=200000){
            reward=10000+(profit-100000)*0.075;
        }
        else {
            if(profit<=400000){
                reward=10000+7500+(profit-200000)*0.05;
            }
            else{
                if(profit<=600000){
                    reward=10000+7500+10000+(profit-400000)*0.03;
                }
                else{
                    if(profit<=1000000){
                        reward=10000+7500+10000+6000+(profit-600000)*0.015;
                    }
                    else{
                        reward=10000+7500+10000+6000+400000*0.015+(profit-1000000)*0.01;
                    }
                }
            }
        }
    }
    cout << reward;
    return 0;
}
