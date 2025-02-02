#include <iostream>
using namespace std;

int c[500005], n, m, arr[500005];
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
    while(m--) {
        int op, x, y;
        cin >> op;
        if(op==1) {
            cin >> x >> y;
            Add(x, 1);
            Add(y+1, -1);
        } else {
            cin >> x;
            cout << GetSum(x)%2 << endl;
        }
    }
    return 0;
}