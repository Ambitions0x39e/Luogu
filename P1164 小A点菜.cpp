#include <iostream>
using namespace std;

int dp[10005];
int n, m;
int arr[1024];
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    dp[0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=m; j>=arr[i]; j--) {
            dp[j]+=dp[j-arr[i]]; // 变形，由于题目要求次数所以不需要用max()来求解最佳情况而是记录次数
        }
    }
    // for(int i=1; i<=m; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[m];
    return 0;
}