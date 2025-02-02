#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
string s;
int a[300005], f[300005];
typedef struct node {
    int val, index;
    bool operator < (const node &x) const {
        if(val==x.val) {
            return a[index]>a[x.index];
        }
        return val>x.val;
    }
} NODE;
NODE arr[200005];
NODE construct(int val, int index) {
    NODE x;
    x.val=val;
    x.index=index;
    return x;
}
priority_queue<NODE, vector<NODE>, less<NODE> > pq;

int main() {
    int n, k;
    cin >> n >> k;
    cin >> s;
    for(int i=1; i<=n; i++) {
        if(s[i-1]=='H') {
            a[i]=a[i-1]+1;
        } else {
            a[i]=a[i-1]-1;
        }
    }
    pq.push(construct(0, 0));
    for(int i=1; i<=n; i++) {
        while(pq.top().index<i-k && !pq.empty()) {
            pq.pop();
        }
        NODE x=pq.top();    
        if(a[i]-a[x.index]<=0) {
            f[i]=x.val+1;
        } else {
            f[i]=x.val;
        }
        pq.push(construct(f[i], i));
    }
    cout << f[n] << endl;
    return 0;
}