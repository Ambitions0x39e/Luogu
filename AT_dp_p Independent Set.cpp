#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
vector<ll> vec[100005];
/*
 f[c][0] -> Black
 f[c][1] -> White
*/
ll f[100005][5];
void dp(int c, int fa) {
    for (int i=0; i<vec[c].size(); i++) {
        if (vec[c][i] == fa) {
            continue;
        }
        int child=vec[c][i];
        dp(vec[c][i], c);
        f[c][0]=(f[c][0]*f[child][1])%MOD; // Black
        f[c][1]=(f[c][1]*((f[child][1]+f[child][0])%MOD))%MOD; // White
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        f[i][0]=1;
        f[i][1]=1;
    }
    for (int i=1; i<=n-1; i++) {
        ll x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dp(1, -1);
    cout << (f[1][0]+f[1][1])%MOD;
    return 0;
}