#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
typedef struct edge {
    int u, v, w;
    bool operator <(const struct edge & t) const {
        return w<t.w;
    }
}EDGE;
EDGE arr[200005];
int ancestors[10005];
int pts[10005];
int n, m, ans, num;
int get_ancestors(int x) {
    return ancestors[x]=((ancestors[x]==x)?x:get_ancestors(ancestors[x]));
}
EDGE newEdge(int v, int w) {
    EDGE e;
    e.v=v;
    e.w=w;
    return e;
}
int main() {
    int n, m;
    cin >> n >> m;
    ans=INT_MAX;
    for(int i=1; i<=n; i++) {
        cin >> pts[i];
        ans=min(ans, pts[i]);
    }
    for(int i=1; i<=m; i++) {
        cin >> arr[i].u >> arr[i].v >> arr[i].w;
        arr[i].w=arr[i].w*2+pts[arr[i].u]+pts[arr[i].v];
    }
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    sort(arr+1, arr+1+m);
    for(int i=1; i<=m; i++) {
        int fa=get_ancestors(arr[i].u);
        int fb=get_ancestors(arr[i].v);
        if(fa!=fb) {
            ancestors[fa]=fb;
            ans+=arr[i].w;
            num++;
        }
    }
    cout << ans;
}