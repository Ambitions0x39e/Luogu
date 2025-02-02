/* 并查集 */
int ancestors[length];
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

/* 01背包 一维优化*/
for(int i=1; i<=n; i++) {
    for(int j=w; j>=cost[i]; j--) {
        dp[j]=max(dp[j], dp[j-cost[i]]+value[i]);
    }
}

/* 完全背包 一维优化*/
for(int i=0; i<n; i++) {
    for(int j=1; j<=m; j++) {
        if(cost[i] > j) {
            dp[j]=dp[j];
        } else {
            dp[j]=max(dp[j], dp[j-cost[i]]+value[i]);
        }
    }
}