#include <iostream>
using namespace std;
typedef struct node {
    int v, w;
}NODE;
int n, W;
NODE arr[100005];
int f[100005];
int main() {
    cin >> n >> W;
    int cnt=1;
    for(int i=1; i<=n; i++) {
        int tv, tw, tm;
        cin >> tv >> tw >> tm;
        int idx=1;
        while(idx<=tm) {
            arr[cnt].v=idx*tv;
            arr[cnt].w=idx*tw;
            tm-=idx;
            idx <<= 1;
            cnt++;
        }
        if(tm!=0) {
            arr[cnt].v=tm*tv;
            arr[cnt].w=tm*tw;
            cnt++;
        }
    }
    for(int i=1; i<cnt; i++) {
        for(int j=W; j>=arr[i].w; j--) {
            f[j]=max(f[j], f[j-arr[i].w]+arr[i].v);
        }
    }
    cout << f[W] << endl;
    return 0;
}