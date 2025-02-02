#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cMax[500005], cMin[500005], n, m, arr[500005];
int LowBit(int x) {
    return x&-x;
}
// int GetSum(int x) { 这段程序不需要这玩意
//     int sum=0;
//     while(x>0) {
//         sum+=c[x];
//         x-=LowBit(x);
//     }
//     return sum;
// }
void Add(int x,int v) {
    while(x<=n) {
        cMax[x]=max(cMax[x], v);
        cMin[x]=min(cMin[x], v);
        x+=LowBit(x);
    }
}
int QueryMax(int x, int y) {
    if(y>x) {
        if(y-LowBit(y)<=x) {
            return max(QueryMax(x, y-1), arr[y]);
        } else {
            return max(QueryMax(x, y-LowBit(y)), cMax[y]);
        }
    }
    return arr[x];
}
int QueryMin(int x, int y) {
    if(y>x) {
        if(y-LowBit(y)<=x) {
            return min(QueryMin(x, y-1), arr[y]);
        } else {
            return min(QueryMin(x, y-LowBit(y)), cMin[y]);
        }
    }
    return arr[x];
}   
int main() {
    memset(cMax, 0, sizeof(cMax));
    memset(cMin, 0x7f, sizeof(cMin));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        Add(i, arr[i]);
    }
    while(m--) {
        int x, y;
        cin >> x >> y;
        cout << QueryMax(x, y)-QueryMin(x, y) << endl;
    }
    return 0;
}