#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int arr[505][505], vis[505][505], n;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int bfs(int t, int lx, int ly) {
    queue<pair<int, int> > q;
    q.push(make_pair(lx, ly));
    vis[lx][ly]=1;
    int cnt=0;
    while(!q.empty()) {
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int xx=x+dx[i], yy=y+dy[i];
            if(xx<1 || xx>n || yy<1 || yy>n) continue;
            if(vis[xx][yy] || (int)abs(arr[xx][yy]-arr[x][y])>t) continue;
            vis[xx][yy]=1;
            cnt++;
            q.push(make_pair(xx, yy));
        }
    }
    return cnt+1;
}
int check(int t) {
    memset(vis, 0, sizeof(vis));
    int ans=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(!vis[i][j]) {
                ans=bfs(t, i, j);
                // cout << '-' << ans << endl;
                if(ans>=round(n*n/2.0)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main() {
    cin >> n;
    int l=10000005, r=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
            l=min(l, arr[i][j]);
            r=max(r, arr[i][j]);
        }
    }
    // cout << l << '\t' << r << endl;
    int mid, ans;
    while(l<=r) {
        mid=(l+r)>>1;
        if(check(mid)) {
            ans=mid;
            // cout << ans << endl;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << ans;
}