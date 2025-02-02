#include <iostream>
using namespace std;

/* 数学 模拟 */

int cnt[15];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=n; i<=m; i++) {
        for(int j=i; j>=1; j/=10) {
            cnt[j%10]++;
        }
    }
    for(int i=0; i<=9; i++) {
        cout<<cnt[i]<<' ';
    }
    return 0;
}