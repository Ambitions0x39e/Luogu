#include <iostream>
#include <vector>
using namespace std;
int f[6005][5], arr[6005];
bool vis[6005];
vector<int> vec[6005];
void dp(int x) {
    f[x][1]=arr[x];
    for (int i=0; i<vec[x].size(); i++) {
        int y=vec[x][i];
        dp(y);
        f[x][0]+=max(f[y][0], f[y][1]);
        f[x][1]+=f[y][0];
    }
    // cout << max(f[x][0], f[x][1]) << endl;
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for (int i=1; i<=n-1; i++) {
        int x, y;
        cin >> x >> y;
        vec[y].push_back(x);
        vis[x]=true;
    }
    int root;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            root=i;
            break;
        }
    }
    dp(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}