#include <iostream>
#include <algorithm>
using namespace std;

/* 数学 */

typedef struct seg{
    int lb, rb;
    
}segment;
segment arr[1000005];
bool sort_by_rb(const segment a, const segment b) {
    return a.rb<b.rb;
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].lb >> arr[i].rb;
    }
    sort(arr, arr+n, sort_by_rb);
    int current_end=0, cnt=0; 
    for(int i=0; i<n; i++) {
        if(current_end<=arr[i].lb) {
            current_end=arr[i].rb;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}