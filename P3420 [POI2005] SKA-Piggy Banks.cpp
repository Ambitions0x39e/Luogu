#include <iostream>
using namespace std;
int ancestors[1000005];
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
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        union_set(x, i);
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        if(get_ancestors(i)==i) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}