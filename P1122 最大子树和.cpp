#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int arr[16005], f[16005];
vector<int> v[16005];
void dp(int c, int fa) {
    f[c]=arr[c];
    for (int i=0; i<v[c].size(); i++) {
        if (v[c][i] == fa) {
            continue;
        }
        dp(v[c][i], c);
        if (f[v[c][i]] > 0) {
            f[c]+=f[v[c][i]];
        }
    }
}
int main () {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dp(1, -1);
    int ans=INT_MIN;
    for (int i=1; i<=n; i++) {
        ans=max(ans, f[i]);
    }
    cout << ans << endl;
}