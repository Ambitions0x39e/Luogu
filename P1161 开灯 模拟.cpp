#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/* 异或 */

int main() {
    int n;
    cin >> n;
    int ans=0;
    for(int i=0; i<n; i++) {
        double d;
        int v;
        cin >> d >> v;
        for(int j=1; j<=v; j++) {
            ans^=(int)(d*j); /* 最后只有一个开关开着代表只有一个数字出现了奇数次，其他数字异或都是偶数次，则结果为0，所以异或所有数字得到结果*/
        }
    }
    cout<<ans;
    return 0;
}