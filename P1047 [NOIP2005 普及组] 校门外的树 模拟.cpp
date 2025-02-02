#include <iostream>
#include <string.h>
using namespace std;

/* 模拟 */

bool vis[10005];
int main() {
    int m, n;
    cin >> m >> n;
    memset(vis, true, sizeof(vis)); 
    while(n--) {
        int lb, rb;
        cin >> lb >> rb;
        for(int i=lb; i<=rb; i++) {
            vis[i]=false;
        }
    }
    int cnt=0;
    for(int i=0; i<=m; i++) {
        cnt+=vis[i]?1:0;
    }
    cout << cnt;
}