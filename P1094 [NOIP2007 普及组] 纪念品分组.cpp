#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  */

int main() {
    int n, maxVal;
    cin >> maxVal;
    cin >> n;
    vector<int> arr(n);
    for(int &i: arr) {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int cnt=0;
    for(int lb=0, rb=n-1; lb<=rb; ) {
        if(arr[lb]+arr[rb]>maxVal) {
            cnt++;
            rb--;
        } else if (arr[lb]+arr[rb]<=maxVal) {
            cnt++;
            lb++; rb--; 
        } else if (lb==rb) {
            cnt++;
            lb++;
        }
    }
    cout<<cnt;
    return 0;
}