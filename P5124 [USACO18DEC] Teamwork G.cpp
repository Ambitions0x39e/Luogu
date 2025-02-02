#include <iostream>
#include <climits>
using namespace std;

int n, k;
int arr[10005];
int f[10005];

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++) {
        int val=arr[i];
        for(int j=i; j>=max(1, i-k+1); j--) {
            val=max(val, arr[j]);
            f[i]=max(f[i], f[j-1]+val*(i-j+1));
            // cout << i << '\t' << f[i] << endl;
        }
    }
    cout << f[n] << endl;
    return 0;
}