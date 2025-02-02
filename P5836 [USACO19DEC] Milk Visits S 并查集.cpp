#include <iostream>
using namespace std;
string cowType;
int ancestors[100005];
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
    int n, m;
    cin >> n >> m;
    cin >> cowType;
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    for(int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        if(cowType[x-1]==cowType[y-1]) {
            union_set(x, y);
        }
    }
    while(m--) {
        int x, y;
        char c;
        scanf("%d %d %c", &x ,&y ,&c);
        if(get_ancestors(x)!=get_ancestors(y)) {
            cout << 1;
        } else if(cowType[x-1]==c) {
            cout << 1;
        } else {
            if(get_ancestors(x)==get_ancestors(y)) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
    }
    return 0;
}