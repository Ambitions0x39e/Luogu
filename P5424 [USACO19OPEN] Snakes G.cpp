#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int n, m;
int arr[405], prefixSum[405], maxV[405][405], dp[405][405];
int main() {
    cin >> n >> m;
    m++;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    for(int i=1; i<=n; i++) {
        maxV[i][i]=arr[i];
        for(int j=i+1; j<=n; j++) {
            maxV[i][j]=max(maxV[i][j-1], arr[j]);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0]=0;
    for(int i=1; i<=n; i++) { 
        for(int j=1; j<=min(m, i); j++) {
            for(int k=i-1; k>=0; k--) {
                dp[i][j]=min(dp[i][j], dp[k][j-1]+maxV[k+1][i]*(i-k)-(prefixSum[i]-prefixSum[k]));
            }
        }
    }
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans=INT_MAX;
    for(int i=1; i<=m; i++) {
        ans=min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}