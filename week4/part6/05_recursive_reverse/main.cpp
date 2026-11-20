#include<iostream>
#include<string>
using namespace std;
void reversefrom(string &arr,int i,int j){
    if(i>=j)return;
    char t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
    reversefrom(arr,i+1,j-1);
}
void reverse(string &arr){
    reversefrom(arr,0,(int)arr.size()-1);
}
int main(){
    string s;
    getline(cin,s);
    reverse(s);
    cout <<s<<"\n";
    return 0;
}