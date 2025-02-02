#include <iostream>
#include <stack>
using namespace std;
typedef struct path {
    int d1, d2;
}PATH;
PATH paths[3005];
int n, m;
int ancestors[3005];
bool succeed[3005];
stack<int> pts;
stack <bool> stat;
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
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    for(int i=0; i<m; i++) {
        cin >> paths[i].d1 >> paths[i].d2;
    }
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        pts.push(x);
    }
    while(!pts.empty()) {
        int x=pts.top();
        pts.pop();
        succeed[x]=true;
        for(int i=0; i<m; i++) {
            if(paths[i].d1==x) {
                if(succeed[paths[i].d1] && succeed[paths[i].d2]) {
                    union_set(paths[i].d1, paths[i].d2);
                }
            } else if(paths[i].d2==x) {
                if(succeed[paths[i].d1] && succeed[paths[i].d2]) {
                    union_set(paths[i].d1, paths[i].d2);
                }
            }
        }
        int cnt=0;
        for(int i=1; i<=n; i++) {
            if(!succeed[i]) {
                continue;
            }
            if(ancestors[i]==i) {
                cnt++;
            }
        }
        if(cnt>1) {
            stat.push(false);
        } else {
            stat.push(true);
        }
    }
    while(!stat.empty()) {
        if(stat.top()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        stat.pop();
    }
    return 0;
}