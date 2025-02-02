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
vector<node> cow_forward[1005], cow_backward[1005];
int n, m, x;
int d1[1005], d2[1005];
bool vis[1005];
void dijkstra_forward(int x) {
    memset(d1, 0x3f, sizeof(d1));
    memset(vis, 0, sizeof(vis));
    d1[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, x));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : cow_forward[u]) {
            if(d1[v.v] > d1[u] + v.w) {
                d1[v.v] = d1[u] + v.w;
                q.push(make_pair(d1[v.v], v.v));
            }
        }
    }
}
void dijkstra_backward(int x) {
    memset(d2, 0x3f, sizeof(d2));
    memset(vis, 0, sizeof(vis));
    d2[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, x));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : cow_backward[u]) {
            if(d2[v.v] > d2[u] + v.w) {
                d2[v.v] = d2[u] + v.w;
                q.push(make_pair(d2[v.v], v.v));
            }
        }
    }
}
int main() {
    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cow_forward[a].push_back(node(b, c));
        cow_backward[b].push_back(node(a, c));
    }
    
    dijkstra_forward(x);
    dijkstra_backward(x);
    int res=0;
    for(int i=1; i<=n; i++) {
        // cout << d1[i] << ' ' << d2[i];
        res=max(res, d1[i]+d2[i]);
    }
    cout << res;
    return 0;
}