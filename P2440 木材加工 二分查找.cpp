#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 二分查找 */

/* 
3 7
232
124
456

114
*/
long long n, m;
long long arr[100005];
int check(long long val) {
    int sum=0;
    for(int i=0; i<n; i++) {
        sum+=arr[i]/val;
    }
    return sum>=m;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    long long lb=0, rb=100000001;
    long long ans;
    while(lb+1<rb) {
        long long mid=(lb+rb)>>1;
        if(check(mid)) {
            lb=mid;
        } else {
            rb=mid;
        }
    }
    cout<<lb;
    return 0;
}