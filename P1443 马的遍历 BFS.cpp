#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

/* BfS */

int n, m;
int dx[]={-2, -1, 1, 2, -2, -1, 1, 2};
int dy[]={-1, -2, -2, -1, 1, 2, 2, 1};
queue< pair<int, int> > q;
int ans[505][505];
bool vis[505][505];
bool out_of_matx(int x, int y) {
    if(x<1 || x>n || y<1 || y>m) {
        return true;
    } 
    return false;
}
int main() {
    int startX, startY;
    cin >> n >> m >> startX >> startY;
    memset(vis, false, sizeof(vis));
    ans[startX][startY]=0;
    vis[startX][startY]=true;
    q.push(make_pair(startX, startY));
    while(!q.empty()) {
        int tx=q.front().first, ty=q.front().second;
        // cout << "-*-" << tx << '\t' << ty << endl;
        q.pop();
        for(int i=0; i<8; i++) {
            int newx=tx+dx[i], newy=ty+dy[i];
            if(out_of_matx(newx, newy) || vis[newx][newy]==true) {
                continue;
            }
            // cout << "--*--" << newx << '\t' << newy << endl;
            ans[newx][newy]=ans[tx][ty]+1;
            vis[newx][newy]=true;
            q.push(make_pair(newx, newy));
        }   
    } 
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            printf("%-5d", vis[i][j]==false? -1 : ans[i][j]);
        }
        cout<<endl;
    }
    return 0;
}