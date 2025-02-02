#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
typedef struct node {
    int lb, rb;
}NODE;
NODE arr[105];
int visited[1024];
long long count() {
    long long result=0;
    for(int i=1; i<=1000; i++) {
        result+=visited[i];
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].lb >> arr[i].rb;
    }
    long long ans=INT_MIN;
    for(int i=1; i<=n; i++) {
        // Choose the [i]th to be kicked out
        memset(visited, 0, sizeof(visited));
        for(int j=1; j<=n; j++) {
            if(j==i) continue;
            for(int k=arr[j].lb; k<arr[j].rb; k++) {
                visited[k]=1;
            }
        }
        ans=max(ans, count());
    }
    cout << ans;
    return 0;  
}