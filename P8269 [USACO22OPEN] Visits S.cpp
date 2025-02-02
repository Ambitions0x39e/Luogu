#include <iostream>
#include <algorithm>
using namespace std;
// typedef long long int64_t;
typedef struct edge {
    int u, v;
    int64_t w;
    bool operator <(const struct edge & t) const {
        return w>t.w;
    }
} EDGE;
EDGE arr[100005];
EDGE makeEdge(int u, int v, int w) { EDGE e; e.u=u; e.v=v; e.w=w; return e; }
int ancestors[100005];
int n;
int get_ancestors(int u) {
    return ancestors[u]==u?u:ancestors[u]=get_ancestors(ancestors[u]);
}
void union_set(int u, int v) {
    ancestors[get_ancestors(u)]=get_ancestors(v);
}
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        int v; 
        int64_t w;
        cin >> v >> w;
        arr[i]=makeEdge(i, v, w);
    }
    sort(arr+1, arr+1+n);
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    int64_t ans=0;
    for(int i=1; i<=n; i++) {
        if(get_ancestors(arr[i].u)==get_ancestors(arr[i].v)) {
            continue;
        }
        ans+=arr[i].w;
        union_set(arr[i].u, arr[i].v);
    }
    cout << ans;
    return 0;
}