#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node {
    int required_time, end_time;
}NODE;
NODE arr[1005];
int n;
bool SortByEndTime(NODE a, NODE b) {
    return a.end_time < b.end_time;
}
bool check(int mid) {
    int current_time=mid;
    for(int i=0; i<n; i++) {
        // cout << "--" << current_time << '\t' << arr[i].required_time << '\t' << arr[i].end_time << endl;
        if(current_time+arr[i].required_time <= arr[i].end_time) {
            current_time+=arr[i].required_time;
        } else {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].required_time >> arr[i].end_time;
    }
    sort(arr, arr+n, SortByEndTime);
    int l=0, r=arr[n-1].end_time;
    int mid, ans=-1;
    while(l<=r) {
        mid=(l+r)>>1;
        // cout << '-' << mid << endl;
        if(check(mid)) {
            ans=mid;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    if(ans==-1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans;
}  