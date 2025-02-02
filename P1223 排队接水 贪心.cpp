#include <iostream>
#include <algorithm>
using namespace std;

/* 贪心 */

int n;
class people {
    public:
        int index, value;
};
people arr[1005];
bool sort_with_val(const people &a, const people &b) {
    return a.value<b.value;
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].value;
        arr[i].index=i+1;
    }
    sort(arr, arr+n, sort_with_val);
    double sum=0;
    for(int i=0; i<n; i++) {
        cout<<arr[i].index<<' ';
        sum+=arr[i].value*(n-i-1);
    }
    sum/=n;
    printf("\n%.2lf", sum);
    return 0;
}