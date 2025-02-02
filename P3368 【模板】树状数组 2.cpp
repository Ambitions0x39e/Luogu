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
    for(int i=1; i<=n; i++) {
        int temp;
        cin >> temp;
        arr[i]=temp;
    }
    while(m--) {
        int op, x, y, t;
        cin >> op;
        if(op==1) {
            cin >> x >> y >> t;
            Add(x, t);
            Add(y+1, -t);
        } else {
            cin >> x;
            cout << GetSum(x)+arr[x] << endl;
        }
    }
    return 0;
}