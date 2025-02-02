#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* 字符串 */

const char *base26= " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool is_number(char c) {
    if(c>='0' && c<='9') {
        return true;
    }
    return false;
}
bool is_alp(char c) {
    if(c>='A' && c<='Z') {
        return true;
    }
    return false;
}
int get_type(string s) {
    int first_num;
    for(int i=0; i<s.length(); i++) {
        if(is_number(i)) {
            first_num=i;
            break;
        } 
    }
    if(is_number(first_num) && is_alp(first_num-1)) {
        return 1; /* XXYY */
    } else {
        return 2; /* RxCy*/
    }
}
string ExcelToRxCy(string s) {
    string res;
    int first_digit;
    for(int i=0; i<s.length(); i++) {
        if(is_number(s[i])) {
            first_digit=i;
            break;
        }
    }
    int pow_=0;
    int x_val=0;
    for(int i=first_digit-1; i>=0; i--) {
        x_val+=(s[i]-'A'+1)*pow(26, pow_++);
    }
    return "R"+s.substr(first_digit, s.length()-first_digit)+"C"+to_string(x_val);
}
string RxCyToExcel(string s) {
    int x_start=s.find('R')+1;
    int y_start=s.find('C')+1;
    string num1=s.substr(x_start, y_start-x_start-1);
    string num2=s.substr(y_start, s.length()-y_start-1);
    string Cval;
    int val2=0;
    for(int i=0; i<num2.length(); i++) {
        val2=val2*10+(num2[i]-'0');
    }

    return Cval+num1;
}
int main() {
    // int n; 
    // cin >> n;    
    // while(n--) {
    //     string s;
    //     cin >> s;
    //     int type=get_type(s);
    //     if(type==1) {
            
    //     } else if (type==2) {

    //     }
    // }


    return 0;
}