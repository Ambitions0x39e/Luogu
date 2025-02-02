#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef struct cow {
    int x, y, d;
} COW;
COW arr[205];
vector<int> vec[205];
bool vis[205];
int cnt;
int calc(int x1, int y1, int x2, int y2) {
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
void dfs(int cur) {
    cnt++;
    vis[cur]=true;
    for(int i=0; i<vec[cur].size(); i++) {
        if(!vis[vec[cur][i]]) {
            dfs(vec[cur][i]);
        }
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].d;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) {
                continue; 
            }
            if(calc(arr[i].x, arr[i].y, arr[j].x, arr[j].y) <= arr[i].d*arr[i].d) {
                vec[i].push_back(j);
            }
        }
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        cnt=0;
        memset(vis, false, sizeof(vis));
        dfs(i);
        ans=max(ans, cnt);
    }
    cout << ans;
    return 0;
}