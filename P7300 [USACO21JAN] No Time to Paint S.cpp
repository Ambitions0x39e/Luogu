#include <iostream>
#include <cstring>
using namespace std;
int arr[100005];
int f[100005], g[100005];
int vis[30];
int main() {
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    for(int i=1; i<=n; i++) {
        arr[i]=str[i-1]-'A'+1;
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        if(!vis[arr[i]]) {
            ans++;
            vis[arr[i]]=1;
        }
        for(int j=arr[i]+1; j<=26; j++) {
            vis[j]=0;
        }
        f[i]=ans;
    }
    memset(vis, 0, sizeof(vis));
    ans=0;
    for(int i=n; i>=1; i--) {
        if(!vis[arr[i]]) {
            ans++;
            vis[arr[i]]=1;
        }
        for(int j=arr[i]+1; j<=26; j++) {
            vis[j]=0;
        }
        g[i]=ans;
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << f[a-1]+g[b+1] << endl;
    }
}