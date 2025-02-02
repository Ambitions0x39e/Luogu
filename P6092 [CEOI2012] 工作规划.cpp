#include <iostream>
using namespace std;

int n, d, m, arr[1000005];
int f[100005];
int check(int x) {
    for(int i=1; i<=n; i++) {
        f[i]=max(f[i-1]+arr[i]-x, 0);
        if(f[i]>d*x) {
            return 0;
        }
    }
    return 1;
}
int main() {
    cin >> n >> d >> m;
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }
    int l=1, r=m;
    int mid;
    int ans;
    while(l<=r) {
        mid=(l+r)/2;
        if(check(mid)) {
            ans=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << ans;
    return 0;
}