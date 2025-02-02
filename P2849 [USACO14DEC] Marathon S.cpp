#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;
int aX[1024], aY[1024];
int f[1024][1024];
int n, K;
int calc(int x, int y) {
    return abs(aY[y]-aY[x])+abs(aX[y]-aX[x]);
}
int main() {
    cin >> n >> K;
    for(int i=1; i<=n; i++) {
        cin >> aX[i] >> aY[i];
    }
    memset(f, 0x3f, sizeof(f));
    f[1][0]=0;
    for(int i=0; i<=n; i++) {
        f[i][i]=0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=min(K, i-1); j++) {
            for(int k=0; k<=j; k++) {
                f[i][j]=min(f[i][j], f[i-k-1][j-k]+calc(i-k-1, i));
            }
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<=K; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << f[n][K] << endl;
    return 0;
}