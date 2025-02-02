#include <iostream>
#include <algorithm>
using namespace std;
int arr[105], arr2[105];
/*
 6
 2 x 2
 4 x 3
 7 x 4
 7 x 7
 9 x 7
 3 x 9
 Diff 4 Expected 3
 */
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        arr2[i]=arr[i];
    }
    sort(arr, arr+n);
    long long diff=0;
    for(int i=0; i<n; i++) {
        if(arr[i]!=arr2[i]) {
            diff++;
        }
    }
    cout << diff-1;
    return 0;
}