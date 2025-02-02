#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node {
    int w, a;
    bool operator <(const struct node &x) const {
        return w>x.w;
    }
} NODE;
NODE arr[200005];
int a[200005], n, m, k;
long long ans;
int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].w >> arr[i].a;
    }
    sort(arr+1, arr+n+1);
    int ind=1;
    for(int i=1; i<=n; i++) {
        while(ind<=i && arr[ind].w-arr[i].w>=k) {
            m+=a[ind];
            ind++;
        }
        if(m<arr[i].a) {
            a[i]=m;
        } else {
            a[i]=arr[i].a;
        }
        m-=a[i];
        ans+=a[i];
    }
    cout << ans << endl;
    return 0;
}