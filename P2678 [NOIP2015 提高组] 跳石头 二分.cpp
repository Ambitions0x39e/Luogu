#include <iostream>
using namespace std;

/* 二分最短跳跃长度*/

int arr[50005];
int l, m, n;
bool check(int mid) {
    int last=0, cnt=0;
    for(int i=0; i<n; i++) {
        // cout<<'-'<<arr[i]-last<<endl;
        if(arr[i]-last<mid) {
            cnt++;
            continue;
        }
        last=arr[i];
    }
    return cnt<=m;
}
int main() {
    cin >> l >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int lb=0, rb=l, mid;
    while(lb<rb) {
        mid=(lb+rb)>>1;
        // cout<<mid<<endl;
        if(check(mid)) {
            lb=mid+1;
        } else {
            rb=mid;
        }
    }
    cout<<lb-1;
    return 0;
}