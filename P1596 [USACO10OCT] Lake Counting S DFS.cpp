#include <iostream>
#include <cstring>
using namespace std;

/* DFS */

char mat[105][105];
bool vis[105][105];
int n, m;
void dfs(int x, int y) {
    if(mat[x][y]!='W' || vis[x][y]) {
        return ;
    }
    vis[x][y]=true;
    for(int i=x-1; i<=x+1; i++) {
        for(int j=y-1; j<=y+1; j++) {
            if(i==x && j==y) {
                continue;
            }
            if(i<0 || j<0 || i>=n || j>=m) {
                continue;
            }
            dfs(i, j);
        }
    }
    return ;
}

int main() {
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j]=='.' || vis[i][j]==true) {
                continue;
            }
            dfs(i, j);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}