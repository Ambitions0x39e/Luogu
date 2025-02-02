#include <iostream>
#include <climits>
using namespace std;

int n, m;
int arr[200005], q[200005], f[200005];
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    int head=0, tail=0, ans=INT_MAX;
    for(int i=1; i<=n; i++) {
        while(head<=tail && i-q[head]>m) {
            head++;
        }
        f[i]=f[q[head]]+arr[i];
        while(head<=tail && f[i]<=f[q[tail]]) {
            tail--;
        }
        q[++tail]=i;
    }
    for(int i=n; i>=n-m+1; i--) {
        ans=min(ans, f[i]);
    }
    cout << ans;
    return 0;
}