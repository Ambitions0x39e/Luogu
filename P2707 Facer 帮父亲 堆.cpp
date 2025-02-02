#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long _int64;
typedef struct node {
    _int64 val, b;
}NODE;
typedef struct cmp {
    bool operator()(const NODE& a, const NODE& b) {
        return a.val < b.val;
    }
}CMP; 
priority_queue<NODE, vector<NODE>, cmp> pq;
NODE newNode(_int64 val, _int64 b) {
    NODE x;
    x.val = val;
    x.b = b;
    return x;
}
int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        _int64 a, b;
        cin >> a >> b;
        pq.push(newNode(a-b, b));
    }
    _int64 sum=0;
    for(int i=0; i<k; i++) {
        if(pq.empty()) {
            break;
        }
        NODE tmp=pq.top();
        pq.pop();
        if(tmp.val<0) {
            continue;
        }
        sum+=tmp.val;
        tmp.val-=tmp.b*2;
        pq.push(tmp);
    }
    cout << sum;
    return 0;
}