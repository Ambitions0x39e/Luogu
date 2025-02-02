#include <iostream>
#include <cmath>
using namespace std;
int arr[200005], lSum[800005], rSum[800005], sum[800005];
void pushUp(int x, int l, int r) {
    int mid=(l+r)>>1;
    int lLen=mid-l+1;
    int rLen=r-mid;
    lSum[x]=lSum[x*2];
    rSum[x]=rSum[x*2+1];
    sum[x]=max(sum[x*2], sum[x*2+1]);
    if(arr[mid]!=arr[mid+1]) {
        sum[x]=max(sum[x], rSum[x*2]+lSum[x*2+1]);  
        if(sum[x*2]==lLen) {
            lSum[x]=lLen+lSum[x*2+1];
        }
        if(sum[x*2+1]==rLen) {
            rSum[x]=rLen+rSum[x*2];
        }
    }
    return ;
}
void construct(int x, int l, int r) {
    sum[x]=lSum[x]=rSum[x]=1;
    if (l==r) {
        return ;
    }
    int mid=(l+r)>>1;
    construct(x<<1, l, mid);
    construct(x<<1|1, mid+1, r);
    pushUp(x, l, r);
    return ;
}
void modify(int x, int l, int r, int k) { 
    if (l==r && l==k) {
        arr[l]=!arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    if (k<=mid) {
        modify(x<<1, l, mid, k);
    } else {
        modify(x<<1|1, mid+1, r, k);
    }
    pushUp(x, l, r);
    return ;
}

int main() {
    int n, q;
    cin >> n >> q;
    construct(1, 1, n);
    while (q--) {
        int x;
        cin >> x;
        modify(1, 1, n, x);
        cout << sum[1] << endl;
    }
    return 0;
}