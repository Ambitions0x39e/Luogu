#include <iostream>
using namespace std;

int c[500005], n, m;
int LowBit(int x) {
    return x&-x;
}
int GetSum(int x) {
    int sum=0;
    while(x>0) {
        sum+=c[x];
        x-=LowBit(x);
    }
    return sum;
}
void Add(int x,int v) {
    while(x<=n) {
        c[x]+=v;
        x+=LowBit(x);
    }
}
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        Add(i, x);
    }
    while(m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op==1) {
            Add(x, y);
        } else {
            cout << GetSum(y)-GetSum(x-1) << endl;
        }
    }
    return 0;
}