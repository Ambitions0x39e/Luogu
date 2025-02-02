#include <iostream>
using namespace std;

/* 并查集 01背包 */

int n, m, w;
int c[10005], d[10005], ancestors[10005], dp[10005];
int get_ancestors(int x) {
    if(ancestors[x]==x) {
        return x;
    } else {
        return ancestors[x]=get_ancestors(ancestors[x]);
    }
}
void union_set(int x, int y) {
    ancestors[get_ancestors(y)]=get_ancestors(x);
}
int main() {
    cin >> n >> m >> w;
    for (int i=1; i<=n; i++) {
        cin >> c[i] >> d[i];
    }
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    for(int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y ;
        union_set(x, y);
    }
    for(int i=1; i<=n; i++) {
        if(ancestors[i]==i) {
            continue;
        }
        c[get_ancestors(i)] += c[i];
        c[i]=0;
        d[get_ancestors(i)]+=d[i];
        d[i]=0;
    }
    // for(int i=1; i<=n; i++) {
    //     cout<<ancestors[i]<<endl;
    //     cout << c[i] << '\t' << d[i] << endl;;
    // }
    for(int i=1; i<=n; i++) {
        for(int j=w; j>=c[i]; j--) {
            dp[j]=max(dp[j], dp[j-c[i]]+d[i]);
        }
    }
    cout << dp[w];
    return 0;
}
