#include <iostream>
#include <string>
using namespace std;

int countLetters(const string &s){
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) cnt++;
    }
    return cnt;
}

int main(){
    string s;
    getline(cin, s);
    cout << countLetters(s) << endl;
    return 0;
}
