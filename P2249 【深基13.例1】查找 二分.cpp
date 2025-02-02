#include <iostream>
#include <vector>
using namespace std;

/* 二分查找 */
/* Test
11 3
1 3 3 3 5 7 9 11 13 15 15
1 3 6
*/
int arr[1000005];
int n, m;
int binary_search(int target) {
    int lb=1, rb=n, mid;
    while(lb<=rb) {
        mid=(lb+rb)>>1;
        if(arr[mid]>=target) {
            rb=mid-1;
        } 
        if(arr[mid]<target) {
            lb=mid+1;
        }
    }
    if(arr[lb]==target) {
        return lb;
    } else {
        return -1;
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    while(m--) {
        int target;
        cin >> target;
        cout<<binary_search(target)<<' ';
    }
    return 0;
}

