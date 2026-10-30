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
#include <cstdlib>
using namespace std;
int main(){
    system("chcp 65001");
    string k="你认为电影";
    int score;
    cin >> score;
    if(score>=9){
        cout << k+" 经典";
    }
    else if(score>=7){
        cout << k+"非常好";
    }
    else if(score>=5){
        cout << k+"一般";
    }
    else{
        cout << k+"烂片";
    }
    return 0;
}
