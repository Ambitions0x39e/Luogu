#include <iostream>
#include <vector>
using namespace std;
const int MOD=1e9+7;
vector<int> vec[100005];
long long f[100005][5]; // Three colors that are available [012]
int n, k;
void dfs(int c, int fa) {
    for (auto i: vec[c]) {
        if (i==fa) {
            continue;
        }
        dfs(i, c);
        f[c][0]=(f[c][0]*(f[i][1]+f[i][2])%MOD)%MOD;
        f[c][1]=(f[c][1]*(f[i][0]+f[i][2])%MOD)%MOD;
        f[c][2]=(f[c][2]*(f[i][0]+f[i][1])%MOD)%MOD;
    }
}
int main() {
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        f[i][0]=1;
        f[i][1]=1;
        f[i][2]=1;
    }
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        f[x][0]=0;
        f[x][1]=0;
        f[x][2]=0;
        f[x][y-1]=1;
    }
    dfs(1, 0);
    cout << (f[1][0]+f[1][1]+f[1][2])%MOD;
    return 0;
}