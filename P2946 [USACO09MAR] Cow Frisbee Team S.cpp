#include <iostream>
using namespace std;
const long long mod=100000000;
long long n, f;
long long arr[2048];
long long dp[2048][2048];
int main() {
    cin >> n >> f;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        arr[i]%=f;
    }
    for(int i=1; i<=n; i++) {
        dp[i][arr[i]]=1;
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=f-1; j++) {
            dp[i][j]=((dp[i][j]+dp[i-1][j])%mod+dp[i-1][(j-arr[i]+f)%f])%mod; // dp[i-1][j] not choose
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<=f; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout <<endl;
    // }
    cout << dp[n][0];
    return 0;
}