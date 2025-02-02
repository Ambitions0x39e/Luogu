#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef struct node {
    int v, w;
    node(int _v, int _w) : v(_v), w(_w) {}
}NODE;
vector<node> G[100010];
int d[100010];
bool vis[100010];
int n, m, s;
void dijkstra(int s) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e: G[u]) {
            int v = e.v, w = e.w;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(make_pair(d[v], v));
            }
        }
    }
}
int main() {
    cin >> n >> m >> s;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(node(v, w));
    }
    dijkstra(s);
    for(int i=1; i<=n; i++) {
        cout << d[i] << ' ';
    }
    return 0;
}