#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct cow {
    int pos, id;
    bool operator <(const struct cow & b)const {
        return pos<b.pos;
    }
}COW;
int n;
map<int, int> cnt;
COW arr[50005];
int q[100005];
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].pos >> arr[i].id;
        cnt[arr[i].id]++;
    }
    int m=cnt.size();
    cnt.clear();
    sort(arr+1, arr+1+n);
    int head=1, tail=0, ttl=0, ans=INT_MAX;
    for(int i=1; i<=n; i++) {
        q[++tail]=i;
        cnt[arr[i].id]++;
        if(cnt[arr[i].id]==1) {
            ttl++;
        }
        while(head<=tail && cnt[arr[q[head]].id]>1) {
            cnt[arr[q[head++]].id]--;
        }
        if(cnt.size()==m) {
            ans=min(ans, arr[q[tail]].pos-arr[q[head]].pos);
        }
    }
    cout << ans;
    return 0;
}