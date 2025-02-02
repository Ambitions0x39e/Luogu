#include <iostream>
#include <vector>
using namespace std;
vector<int> vecX(1024*1024, 0), vecY(1024*1024, 0), vecZ(1024*1024, 0);
int main() {
    int n, q;
    cin >> n >> q;
    long long res=0;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        long long index; // Create mapping
        
        // For each dim calculate if it is full, full then add 1 to result
        index=y*n+z; 
        vecX[index]++;
        res+=vecX[index]==n?1:0;

        index=x*n+z;
        vecY[index]++;
        res+=vecY[index]==n?1:0;

        index=x*n+y;
        vecZ[index]++;
        res+=vecZ[index]==n?1:0;
        cout << res << endl;

        // for(int i=0; i<4; i++) {
        //     cout << vecX[i] << " ";
        // }
        // cout << endl;
        // for(int i=0; i<4; i++) {
        //     cout << vecY[i] << " ";
        // }
        // cout << endl;
        // for(int i=0; i<4; i++) {
        //     cout << vecZ[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}