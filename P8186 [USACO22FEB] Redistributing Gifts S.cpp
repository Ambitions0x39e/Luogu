#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool succeed;
int arr[505][505], vis[505];
vector<int> g[505];
void dfs(int x, int start) {
    if(x==start) {
        succeed=true;
        return ;
    }
    if(vis[x]) {
        return ;
    }
    vis[x]=1;
    for(int i=0; i<g[x].size(); i++) {
        if(!vis[g[x][i]] && !succeed) {
            dfs(g[x][i], start);
        }
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; arr[i][j]!=i; j++) {
            g[i].push_back(arr[i][j]);
        }
    }
    for(int i=1; i<=n; i++) {
        succeed=false;
        for(int j=0; j<g[i].size(); j++) {
            memset(vis, 0, sizeof(vis));
            dfs(g[i][j], i);
            if(succeed) {
                cout << g[i][j] << endl;
                break;
            }
        }
        if(!succeed) {
            cout << i << endl;
        }
    }
    return 0;
}