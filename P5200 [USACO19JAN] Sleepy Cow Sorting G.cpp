#include <iostream>
using namespace std;

int c[500005], n, m;
int LowBit(int x) {
    return x&-x;
}
int GetSum(int x) {
    int sum=0;
    while(x>0) {
        sum+=c[x];
        x-=LowBit(x);
    }
    return sum;
}
void Add(int x,int v) {
    while(x<=n) {
        c[x]+=v;
        x+=LowBit(x);
    }
}

int arr[100005];
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    int ans=1;
    Add(arr[n], 1);
    for(int i=n-1; i>=1; i--) {
        if(arr[i] < arr[i+1]) {
            Add(arr[i], 1);
            ans++;
        } else {
            break;
        }
    }
    ans=n-ans;
    cout << ans << endl;
    for(int i=1; i<=ans; i++) {
        cout << ans-i+GetSum(arr[i]) << ' ';
        // cout << ans-i << ' ' << GetSum(arr[i]) << endl;
        Add(arr[i], 1);
    }
    return 0;
}