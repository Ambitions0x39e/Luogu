#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long x, y;
        x=4, y=4;
        long long sum=0;
        while (x<=n) {
            x=x*10+4;
            y=y*10+9;
            if(x<=n) {
                sum+=min(n, y)-x;
            }
        }   
        cout << sum << endl;
    }
    return 0;
}