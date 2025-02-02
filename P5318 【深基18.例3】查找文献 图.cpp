#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
vector<int> graph[100005];
bool vis[100005];
void dfs(int layer) {
    cout << layer << ' ';
    vis[layer] = true;
    for(auto i: graph[layer]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
}
void bfs() {
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()) {
        int top=q.front();
        q.pop();
        cout << top << ' ';
        for(auto i: graph[top]) {
            if(!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    memset(vis, false, sizeof(vis));
    dfs(1);
    cout << endl;
    memset(vis, false, sizeof(vis));
    bfs();
    return 0;
}