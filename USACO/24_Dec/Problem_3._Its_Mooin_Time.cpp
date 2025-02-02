#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
vector<string> vec;
string str;
int n, f;
int dp_change1[20005], dp_nchange[20005];
/* 
 DP Change1 stores the value when the array is changed once 
 It is inherited from DP not change and leave the 3-letter position to store
 DP not change stores the value when the array is never changed and the amount of str
 is recorded by comparing nearby pos.
*/
int first_3_match(int pos, string match) {
    return (match[0]==str[pos-2])+(match[1]==str[pos-1])+(match[2]==str[pos]);
}
void work(string match) {
    memset(dp_change1, 0, sizeof(dp_change1));
    memset(dp_nchange, 0, sizeof(dp_nchange));
    for(int i=3; i<=n; i++) {
        if(first_3_match(i, match)==2) {
            dp_change1[i]=max(dp_change1[i], dp_nchange[i-3]+1);
        } else if (first_3_match(i, match)==3) {
            dp_nchange[i]=max(dp_nchange[i], dp_nchange[i-3]+1);
            dp_change1[i]=max(dp_change1[i], dp_change1[i-3]+1);
        }
        dp_nchange[i]=max(dp_nchange[i], dp_nchange[i-1]);
        dp_change1[i]=max(dp_change1[i], dp_change1[i-1]);
    }
    for(int i=3; i<=n; i++) {
        if(dp_nchange[i]>=f || dp_change1[i]>=f) {
            vec.push_back(match);
            break;
        }
    }
}
int main() {
    cin >> n >> f;
    cin >> str;
    str=" "+str;
    for (char x='a'; x<='z'; x++) {
        for (char y='a'; y<='z'; y++) {
            if(x==y) {
                continue;
            }
            string match="";
            // Add to match with structure xyy
            match+=x;
            match+=y;
            match+=y;
            work(match);
        }
    }
    cout << vec.size() << endl;
    for (auto i: vec) {
        cout << i << endl;
    }
    return 0;

}