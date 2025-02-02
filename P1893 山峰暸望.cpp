#include <iostream>
#include <climits>
using namespace std;
int arr[10005];
int left_continuous[10005], right_continuous[10005];
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    arr[0]=arr[n+1]=INT_MAX;
    /*
        left_continuous[i]  means the longest sub-array ends with i with asc. 
        right_continuous[i] means the longest sub-array starts with i with desc.
    */
    for(int i=1; i<=n; i++) {
        if(arr[i-1]<=arr[i]) {
            left_continuous[i]=left_continuous[i-1]+1;
        } else {
            left_continuous[i]=1;
        }
    }
    for(int i=n; i>=1; i--) {
        if(arr[i]>=arr[i+1]) {
            right_continuous[i]=right_continuous[i+1]+1;
        } else {
            right_continuous[i]=1;
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        ans=max(ans, left_continuous[i]+right_continuous[i]-1);
    }
    cout << ans;
    return 0;
}