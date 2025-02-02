#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
string arr;
int v[300005];
int main() {
    cin >> n;
    int len=0, ans=0;
    cin >> arr;
    arr="0"+arr+"0";
    
    for(int i=1; i<=n; i++) {
        if (arr[i]=='1') {
            len++;
        } else if (len!=0) {
            v[++ans]=len;
            len=0;
        }
    }
    if (len!=0) {
        v[++ans]=len;
        len=0;
    }
    int day=INT_MAX;
    day=min(day, v[1]-1);
    if(arr[1] == '0') {
        day=min(day, (v[1]-1)/2);
    }
    for(int i=2; i<ans; i++) {
        day=min(day, (v[i]-1)/2);
    }
    day=min(day, v[ans]-1);
    if(arr[n] == '0') {
        day=min(day, (v[ans]-1)/2);
    }
    // cout << day << endl;
    int res=0;
    for(int i=1; i<=ans; i++) {
        // res
        // cout << v[i] << ' ';
        res+=ceil((double)v[i]/(day*2+1));
    }
    cout << res;
    // cout << endl << res;
    return 0;  
}