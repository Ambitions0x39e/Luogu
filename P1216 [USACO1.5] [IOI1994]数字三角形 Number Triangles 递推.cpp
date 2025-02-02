#include <iostream>
#include <queue>
using namespace std;

/* 递推 倒推 */

int triangle[1005][1005];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin >> triangle[i][j];
        }
    }
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<=i; j++) {
            triangle[i][j]+=max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<=i; j++) {
    //         cout << triangle[i][j] << ' ';
    //     }
    //     cout<<endl;
    // }
    cout<<triangle[0][0];
}