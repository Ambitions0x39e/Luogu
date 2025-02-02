#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node {
    int x, y;
    bool operator <(const struct node & t)const {
        return x<t.x;
    }
}NODE;
NODE arr[200005];
int f[30000005], n, m;
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].x >> arr[i].y;
        m=max(m, arr[i].y);
    }
    sort(arr+1, arr+n+1);
    int j=n;
    for(int i=m; i>=1; i--) {
        f[i]=f[i+1];
        while(j>=1 && arr[j].x==i) {
            f[i]=max(f[i], f[arr[j].y+1]+arr[j].y-arr[j].x+1);
            j--;
        }
    }
    cout << f[1] << endl;
    return 0;
}