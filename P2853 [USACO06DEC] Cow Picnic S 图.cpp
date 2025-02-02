#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/* 图 */

vector<int> graph[1024];
int cows[1024];
bool vis[1024];
int cnt[1024]={0};
int k, m, n, result;
void dfs(int x) {
    // cout << x << endl;
    cnt[x]++;
    vis[x]=true;
    for(int i: graph[x]) {
        // cout << '-' << i << endl;
        if(vis[i]) {
            continue;
        }
        dfs(i);
    }
}
int main() {
    cin >> k >> n >> m;
    for(int i=0; i<k; i++) {
        cin >> cows[i];
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    // for(int i=1; i<n; i++) {
    //     cout << i << ":";
    //     for(auto j: graph[i]) {
    //         cout << '\t' << j;
    //     }
    //     cout << endl;
    // }
    for(int i=0; i<k; i++) {
        memset(vis, false, sizeof(vis));
        dfs(cows[i]);
    }
    for(int i=1; i<=n; i++) {
        if(cnt[i]==k) {
            result++;
        }
    }
    cout << result;
    return 0;
}