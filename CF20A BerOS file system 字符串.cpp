#include <iostream>
#include <cstring>
using namespace std;

/* 字符串 */

bool only_home(string s) {
    for(int i=0; i<s.length(); i++) {
        if(s[i]!='/') {
            return false;
        }
    }
    return true;
}
int main() {
    string s;
    cin >> s;  
    if(only_home(s)) {
        cout<<'/';
        return 0;
    }
    while(s[s.length()-1]=='/') {
        s.pop_back();
    }
    char previous=NULL; 
    for(int i=0; i<s.length(); i++) {
        if(previous=='/' && s[i]=='/') {
            previous=s[i];
            continue;
        }
        cout<<s[i];
        previous=s[i];
    }
    return 0;
}