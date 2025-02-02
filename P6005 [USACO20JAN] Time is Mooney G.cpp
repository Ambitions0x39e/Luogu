#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, c;
int arr[1024];
int f[1024][1024];
vector<int> graph[1024];

int main() {
    cin >> n >> m >> c;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    memset(f, -1, sizeof(f));
    f[0][1]=0;
    for(int i=1; i<=1000; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=0; k<graph[j].size(); k++) {
                if(f[i-1][graph[j][k]]!=-1) {
                    f[i][j]=max(f[i][j], f[i-1][graph[j][k]]+arr[j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=1; i<=1000; i++) {
        ans=max(f[i][1]-c*i*i, ans);
    }
    cout << ans;
    return 0;
}