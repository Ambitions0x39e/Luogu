#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k, t;
int matrix[4005][4005];
int f[4005][4005];
int q[4005];
int main() {
    cin >> n >> m >> k >> t;
    for(int i=0; i<k; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        matrix[x][y]=v;
    }
    int head=1, tail=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=t; j++) {
            while(head <= tail && f[i-1][j]>=f[i-1][q[tail]]) {
                tail--;
            }
            q[++tail]=j;
        }
        for(int j=1; j<=m; j++) {
            int position=j+t;
            if(position<=m) {
                while(head <= tail && f[i-1][position]>=f[i-1][q[tail]]) {
                    tail--;
                }
                q[++tail]=position;
            }
            while(q[head]+t<j) {
                head++;
            }
            f[i][j]=f[i-1][q[head]]+matrix[i][j];
        }
        head=1, tail=0; 
        memset(q, 0, sizeof(q));
    }
    int ans=0;
    for(int i=1; i<=m; i++) {
        ans=max(ans, f[n][i]);
    }
    cout << ans << endl;
    return 0;
}