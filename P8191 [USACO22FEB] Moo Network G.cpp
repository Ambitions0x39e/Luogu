#include <iostream>
#include <algorithm>
using namespace std;

typedef struct edge {
    int u, v;
    long long w;
    bool operator <(const struct edge & t) const {
        return w<t.w;
    }
}EDGE;
typedef struct pos {
    long long x, y;
    bool operator <(const struct pos & t)const {
        return x<t.x;
    }
}POS;

POS positions[200005];
EDGE arr[15000000];
int ancestors[200005];
int n, m;
int get_ancestor(int x) {
    return ancestors[x]=((ancestors[x]==x)?x:get_ancestor(ancestors[x]));
}
long long distance(POS a, POS b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> positions[i].x >> positions[i].y;
    }
    sort(positions+1, positions+1+n);
    int current;
    for(int i=1; i<n; i++) {
        current=i+1;
        for(int j=1; j<=75; j++) { //查找从当前位置往后的75个节点
            arr[++m].u=i;
            arr[m].v=current;
            arr[m].w=distance(positions[i], positions[current]);
            current++;
            if(current>n) {
                break;
            }
        }
    }   
    for(int i=1; i<=n; i++) {
        ancestors[i]=i;
    }
    sort(arr+1, arr+1+m);
    long long result=0, ttl=n;
    for(int i=1; i<=m; i++) {
        int u=arr[i].u, v=arr[i].v;
        long long w=arr[i].w;
        if(get_ancestor(u)==get_ancestor(v)) {
            continue;
        }
        ancestors[get_ancestor(u)]=get_ancestor(v);
        result+=w;
        ttl--;
        if(!ttl) {
            break;
        }
    }
    cout << result;
    return 0;
}