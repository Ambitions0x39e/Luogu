#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node {
    int ind, value;
    bool operator <(const struct node & t)const {
        return value>t.value;
    }
}NODE;
NODE points[1000005];
int c[300005], n, m;
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
    cin >> n;
    int cnt=0;
    for(int i=1; i<=n; i++) {
        cin >> points[i].value;
        points[i].ind=i;
    }
    sort(points+1, points+n+1);
    for(int i=1; i<=n; i++) {
        int ind_i=points[i].ind;
        int lr=GetSum(ind_i-1);
        int rr=GetSum(n)-GetSum(ind_i);
        if(lr>rr*2 || rr>lr*2) {
            cnt++;
        }
        Add(points[i].ind, 1);
    }
    cout << cnt << endl;
    return 0;
}