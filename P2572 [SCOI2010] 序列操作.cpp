#include <iostream>
using namespace std;
typedef struct node {
    int l, r;
    long long val, lzt; 
}NODE;
NODE t[400005];
int arr[100005];
void construct (int s, int l, int r) {
    t[s].l=l;
    t[s].r=r;
    if (l==r) {
        t[s].val=arr[l];
        return ;
    }
    int mid=(l+r)/2;
    construct(s*2, l, mid);
    construct(s*2+1, mid+1, r);
    t[s].val=t[s*2].val+t[s*2+1].val;
    return ;
}
void spread(int s) {
    if (t[s].lzt !=0) {
        int x=s*2;
        t[x].val+=t[s].lzt*(t[x].r-t[x].l+1);
        t[x].lzt+=t[s].lzt;
        x++;
        t[x].val+=t[s].lzt*(t[x].r-t[x].l+1);
        t[x].lzt+=t[s].lzt;
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
void modify (int s, int x, int y, int k) {
    if (x<=t[s].l && y>=t[s].r) {
        t[s].val+=(long long)k*(t[s].r-t[s].l+1);
        t[s].lzt+=k;
        return ;
    }
    spread(s);
    int mid=(t[s].l+t[s].r)/2;
    if (x<=mid) {
        modify(s*2, x, y, k);
    }
    if (y>mid) {
        modify(s*2+1, x, y, k);
    }
    t[s].val=t[s*2].val+t[s*2+1].val;
    return ;
}
int main() {
    int n, m;
    cin >> n >> m;
    return 0;
}