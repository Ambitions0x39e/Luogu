#include <iostream>
using namespace std;

/* 并查集 */

int ancestors[5005];
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
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    while(m--) {
        int i, j;
        cin >> i >> j;
        union_set(i, j);
    }
    while(p--) {
        int i, j;
        cin >> i >> j;
        if(get_ancestors(i) == get_ancestors(j)) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}