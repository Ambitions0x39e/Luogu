#include <iostream>
using namespace std;
typedef struct node {
    int l, r;
    long long val, lzt; 
}NODE;
NODE t[400005];
void construct (int s, int l, int r) {
    t[s].l=l;
    t[s].r=r;
    if (l==r) {
        t[s].val=0;
        return ;
    }
    int mid=(l+r)/2;
    construct(s*2, l, mid);
    construct(s*2+1, mid+1, r);
    t[s].val=t[s*2].val+t[s*2+1].val;
    return ;
}
void spread(int s) {
    if (t[s].lzt!=0) {
        int x=s*2;
        t[x].lzt^=1;
        t[x].val=(t[x].r-t[x].l+1)-t[x].val;
        x++;
        t[x].lzt^=1;
        t[x].val=(t[x].r-t[x].l+1)-t[x].val;

        t[s].lzt=0;
    }
    return ;
}
long long query (int s, int x, int y) {
    if (x<=t[s].l && y>=t[s].r) {
        return t[s].val;
    }
    spread(s);
    int mid=(t[s].l+t[s].r)/2;
    long long ans=0;
    if (x<=mid) {
        ans+=query(s*2, x, y);
    }
    if (y>mid) {
        ans+=query(s*2+1, x, y);
    }
    return ans;
}
void modify (int s, int x, int y) {
    if (x<=t[s].l && y>=t[s].r) {
        t[s].val=(t[s].r-t[s].l+1)-t[s].val;
        // t[s].val+=(long long)k*(t[s].r-t[s].l+1);
        t[s].lzt^=1;
        return ;
    }
    spread(s);
    int mid=(t[s].l+t[s].r)/2;
    if (x<=mid) {
        modify(s*2, x, y);
    }
    if (y>mid) {
        modify(s*2+1, x, y);
    }
    t[s].val=t[s*2].val+t[s*2+1].val;
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    construct(1, 1, n);
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op==0) {
            modify(1, x, y);
        } else {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}