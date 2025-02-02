#include <iostream>
#include <algorithm>
using namespace std;
typedef struct edge {
    int u, v, w;
    bool operator <(const struct edge & t) const {
        return w<t.w;
    }
}EDGE;
int n, c;
int pos[2048][2];
int workout[2048][2048];
int ancestors[5005];
EDGE arr[2048*2048];
EDGE makeEdge(int u, int v, int w) {
    EDGE e;
    e.u = u;
    e.v = v;
    e.w = w;
    return e;
}
int get_ancestors(int x) {
    return ancestors[x]=((ancestors[x]==x)?x:get_ancestors(ancestors[x]));
}
int main() {
    cin >> n >> c;
    for(int i=1; i<=n; i++) {
        cin >> pos[i][0] >> pos[i][1];
    }
    int cnt=0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int t=(pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0]) + (pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]);
            if(t<c) {
                continue;
            }
            arr[++cnt]=makeEdge(i, j, t);
        }
    }
    sort(arr+1, arr+1+cnt);
    int ans=0, num=0;
    for(int i=1; i<=n; i++) {
        ancestors[i]=i; // 调了半个小时没加这个
    }
    for(int i=1; i<=cnt; i++) {
        int fa=get_ancestors(arr[i].u);
        int fb=get_ancestors(arr[i].v);
        if(fa!=fb) {
            ancestors[fa]=fb;
            ans+=arr[i].w;
            num++;
        }
    }
    if(num!=n-1) {
        cout << -1 << endl;
    } else {
        cout << ans;
    }
    return 0;
}