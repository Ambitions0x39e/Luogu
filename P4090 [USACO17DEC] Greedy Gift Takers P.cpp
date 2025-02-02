#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, arr[100005], arr2[100005];
bool cmp(int a, int b) {
    return a>b;
}
int check(int x) {
    memset(arr2, 0, sizeof(arr2));
    memcpy(arr2, arr, sizeof(arr));
    sort(arr2+1, arr2+x, cmp);
    int location=x-1;
    for(int i=1; i<x; i++) {
        if(arr2[i]<location) {
            return 0;
        } else {
            location--;
        }
    }
    return 1;
}
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        arr[i]=n-arr[i]-1;
    }
    int l=1, r=n;
    int mid, ans;
    while(l<=r) {
        mid=(l+r)>>1;
        if(check(mid)) {
            ans=mid;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout << n-ans;
    return 0;
}