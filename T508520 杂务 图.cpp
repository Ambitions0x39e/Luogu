#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[10005];
int main() {
    int n; 
    cin >> n;
    for(int i=0; i<n; i++) {
        int id, len;
        cin >> id >> len;
        ans[id] = len;
        while(true) {
            int x;
            cin >> x;
            if(x==0) {
                break;
            }
            ans[id]=max(ans[id], ans[x]+len);
        }
    }
    int res=0;
    for(int i=1; i<=n; i++) {
        res=max(res, ans[i]);
    }
    cout<<res;
    return 0;
}