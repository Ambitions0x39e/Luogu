#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dx[]={0, 0, -1, 1, 0, 0};
int dy[]={-1, 1, 0, 0, 0, 0};
int dz[]={0, 0, 0, 0, -1, 1};
int find_opposite(int i) {
    switch (1)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    case 3:
        return 2;
    case 4:
        return 5;
    case 5:
        return 4;
    }
}
typedef struct node {
    bool have;
    bool used[10];

}NODE;
NODE arr[1000][1000][1000];
int main() {
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                arr[i][j][k].have=true;
                memset(arr[i][j][k].used, true, sizeof(arr[i][j][k].used));
            }
        }
    }
    int ans=0;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        x=x+1, y=y+1, z=z+1;
        arr[x][y][z].have=false;
        for(int i=0; i<6; i++) {
            int nx=x+dx[i], ny=y+dy[i], nz=z+dz[i];
            if (nx<1 || nx>n || ny<1 || ny>n || nz<1 || nz>n) continue;
            if (arr[nx][ny][nz].have==false && 
                arr[x][y][z].used[i]==true && 
                arr[nx][ny][nz].used[find_opposite(i)]==true) {
                    ans++;
                    arr[x][y][z].used[i]=false;
                    arr[nx][ny][nz].used[find_opposite(i)]=false;
            }
        }
        cout << ans;
    }
    return 0;
}