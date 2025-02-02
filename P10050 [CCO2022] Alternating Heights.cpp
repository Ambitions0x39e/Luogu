#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, k, q, arr[3005], f[3005], din[3005];
vector<int> vec[3005];
bool flag[3005];
int check(int lb, int x) {
    for(int i=1; i<=k; i++) {
        vec[i].clear();
    }
    memset(din, 0, sizeof(din));
    memset(flag, false, sizeof(flag));  
    for(int i=lb+1; i<=x; i+=2) {
        vec[arr[i]].push_back(arr[i-1]);
        din[arr[i-1]]++;
        flag[arr[i]]=true;
        flag[arr[i-1]]=true;
        if(i<n && i!=x) {
            vec[arr[i]].push_back(arr[i+1]);
            din[arr[i+1]]++;
            flag[arr[i]]=true;
            flag[arr[i+1]]=true;
        }
    }
    queue<int> q;
    int cnt=0;
    for(int i=1; i<=k; i++) {
        if(flag[i]) {
            cnt++;
            if(din[i]==0) {
                q.push(i);
                cnt--;
            }
        }
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v: vec[u]) {
            din[v]--;
            if(din[v]==0) {
                q.push(v);
                cnt--;
            }
        }
    }
    return cnt==0?true:false;
    // bool succeed=true;
    // for(int i=lb; i<=n; i++) {
    //     if(din[arr[i]]>0) {
    //         succeed=false;
    //         break;
    //     }
    // }
    // return succeed;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> q;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++) {
        int l=i, r=n;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(check(i, mid)) {
                f[i]=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
    }
    while(q--) {
        int lb, rb;
        cin >> lb >> rb;
        if(f[lb]>=rb) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}