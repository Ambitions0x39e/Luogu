#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int din[5005], dout[5005], val[5005], ans;
vector<int> vec[5005];
queue<int> q;
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        din[y]++;
        dout[x]++;
    } 
    for(int i=1; i<=n; i++) {
        if(din[i]==0) {
            val[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto i: vec[u]) {
            din[i]--;
            val[i]=(val[i]+val[u])%80112002;
            if(din[i]==0) {
                q.push(i);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(dout[i]==0) {
            ans=(ans+val[i])%80112002;
        }
    }
    cout<<ans;
    return 0;
}