#include <iostream>
using namespace std;
/* 完全背包 */
int cost[10005], value[10005];
int dp[10005];
int main() {
    int m, n;
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        cin >> value[i] >> cost[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=1; j<=m; j++) {
            if(cost[i] > j) {
                dp[j]=dp[j];
            } else {
                dp[j]=max(dp[j], dp[j-cost[i]]+value[i]);
            }
        }
    }
    cout << dp[m];
    return 0;
}