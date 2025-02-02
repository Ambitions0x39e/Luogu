#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct node {
    int position, point;
    bool operator <(const struct node & t) const {
        return position<t.position;
    }
}NODE;
int n;
NODE arr[1024];
int f[1024][1024];
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].position >> arr[i].point;
    }
    sort(arr+1, arr+1+n);
    int ans=0;
    for(int j=1; j<=n; j++) {
        int k=j;
        int x=arr[j].point;
        for(int i=j+1; i<=n; i++) {
            while(k>=1 && arr[i].position-arr[j].position >= arr[j].position-arr[k].position) {
                x = max(x, f[j][k] + arr[j].point);
                k--;
            }
            f[i][j]=x;
            ans=max(ans, f[i][j]+arr[i].point);
        }
    }
    memset(f, 0, sizeof(f));
    for(int j=n; j>=1; j--) {
        int k=j;
        int x=arr[j].point;
        for(int i=j-1; i>=1; i--) {
            while(k<=n && arr[j].position-arr[i].position >= arr[k].position-arr[j].position) {
                x = max(x, f[j][k] + arr[j].point);
                k++;
            }
            f[i][j]=x;
            ans=max(ans, f[i][j]+arr[i].point);
        }
    }
    cout << ans;
    return 0;
}