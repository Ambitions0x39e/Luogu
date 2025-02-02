#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector<int> vec[100005];
int ans;
/* 

0，1，2分别表示父亲放天线、儿子放天线、自己放天线的状态。

*/
int dp(int c, int fa) {
    int res=0;
    for(int i=0; i<vec[c].size(); i++) {
        if(vec[c][i] == fa) {
            continue;
        }
        int tres=dp(vec[c][i], c);
        if (tres==0) { // 父亲放
            res=2;
        } else if (tres==2 && res!=2) {
            res=1;
        }
    }
    if (res==2) {
        ans++;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n-1; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    if (dp(1, -1)==0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}