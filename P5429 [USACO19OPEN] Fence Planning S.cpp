#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef struct cow {
    int x, y;
    int id;
} COW;
bool vis[100005];
vector<int> graph[100005];
COW arr[100005];
int ancestors[100005];
int minX, minY, maxX, maxY;
int get_ancestor(int x) {
    return ancestors[x]==x?x:ancestors[x]=get_ancestor(ancestors[x]);
}
void union_set(int x, int y) {
    ancestors[get_ancestor(x)] = get_ancestor(y);
}
void dfs(int x) {
    vis[x]=true;
    minX=min(minX, arr[x].x);
    minY=min(minY, arr[x].y);
    maxX=max(maxX, arr[x].x);
    maxY=max(maxY, arr[x].y);
    for(int i=0; i<graph[x].size(); i++) {
        if(vis[graph[x][i]]) {
            continue;
        }
        dfs(graph[x][i]);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        ancestors[i] = i;
    }
    for(int i=1; i<=n; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].id = i;
    }
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans=INT_MAX;
    for(int i=1; i<=n; i++) {
        if(vis[get_ancestor(i)]) {
            continue;
        }
        minX=arr[i].x;
        minY=arr[i].y;
        maxX=arr[i].x;
        maxY=arr[i].y;
        dfs(i);
        ans=min(ans, (maxX-minX)*2+(maxY-minY)*2);
    }
    cout << ans << endl;
    return 0;
}