#include <iostream>
#include <map>
using namespace std;

/* STL / 二分 */

typedef long long _int64;
_int64 arr[200005];
map<_int64, _int64> mat;
int main() {
    int n;
    _int64 c;
    cin >> n >> c;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        mat[arr[i]]++;
    }
    _int64 ans=0;
    for(int i=0; i<n; i++) {
        ans+=mat[arr[i]-c];
    }
    cout<<ans;
    return 0;
}