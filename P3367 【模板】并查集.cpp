#include <iostream>
using namespace std;
int ancestors[10005];
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
int n, m;
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    while(m--) {
        int z, x, y;
        cin >> z >> x >> y;
        if(z==1) {
            union_set(x, y);
        } else {
            if(get_ancestors(x)==get_ancestors(y)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}