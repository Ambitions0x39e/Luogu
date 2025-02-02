#include <iostream>
#include <map>
#include <vector>
using namespace std;

/* 字典对照 */

map<int, bool> dict;
int main() {
    int n;
    cin >>n;
    for(int i=0; i<7; i++) {
        int x;
        cin >> x;
        dict[x]=true;
    }
    vector<int> cnt(7);
    while(n--) {
        int in_range=0;
        for(int i=0; i<7; i++) {
            int x;
            cin >> x;
            if(dict[x]) {
                in_range++;
            }
        }
        cnt[7-in_range]++;
    }
    for(int i: cnt) {
        cout<<i<<' ';
    }
    return 0;
}