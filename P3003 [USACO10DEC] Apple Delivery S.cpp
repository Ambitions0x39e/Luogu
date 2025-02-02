#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef struct node {
    int v, w;
    node(int v, int w) : v(v), w(w) {}
}NODE;
int c, p, pa1, pb, pa2;
vector<NODE> G[100005];
int d[100005];
bool vis[100005];
void dijkstra(int x) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    d[x]=0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, x));
    while(!q.empty()) {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto i: G[u]) {
            int v=i.v, w=i.w;
            if(d[v]>d[u]+w) {
                d[v]=d[u]+w;
                q.push(make_pair(d[v], v));
            }
        }
    }
}
int main() {
    cin >> c >> p >> pb >> pa1 >> pa2;
    for(int i=0; i<c; i++) {
        int p1, p2, d;
        cin >> p1 >> p2 >> d;
        G[p1].push_back(node(p2, d));
        G[p2].push_back(node(p1, d));
    }
    dijkstra(pb);
    int min_part1=min(d[pa1],d[pa2]);
    dijkstra(pa1);
    cout << min_part1+d[pa2];
    return 0;
}