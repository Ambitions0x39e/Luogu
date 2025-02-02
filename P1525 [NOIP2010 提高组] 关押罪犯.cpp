#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node {
    int x, y, val;
    bool operator < (const struct node & t)const {
        return val>t.val;
    }
}NODE;
NODE arr[200005];
int ancestors[40005], b[40005];
int get_ancestors(int x) {
    if(ancestors[x]==x) {
        return x;
    } else {
        return ancestors[x]=get_ancestors(ancestors[x]);
    }
}
void union_set(int x, int y) {
    ancestors[get_ancestors(y)]=get_ancestors(x);
}
bool check(int x, int y) {
    if(get_ancestors(x)==get_ancestors(y)) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].val;
    }
    sort(arr, arr+m);
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    for(int i=0; i<m; i++) {
        if(check(arr[i].x, arr[i].y)) {
            cout << arr[i].val << endl;
            return 0;
        }
        if(b[arr[i].x]==0) {
            b[arr[i].x]=get_ancestors(arr[i].y);
        } else {
            ancestors[get_ancestors(b[arr[i].x])]=get_ancestors(arr[i].y);
        }
        if(b[arr[i].y]==0) {
            b[arr[i].y]=get_ancestors(arr[i].x);
        } else {
            ancestors[get_ancestors(b[arr[i].y])]=get_ancestors(arr[i].x);
        }
    }
    cout << 0 << endl;
    return 0;
}