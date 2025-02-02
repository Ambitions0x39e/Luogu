#include <iostream>
using namespace std;

typedef struct node {
    int lb, rb;
}NODE;
int n;
NODE arr[1000005];
int q[1000005];
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].lb >> arr[i].rb;
    }
    int head=1, tail=0, ans=0;
    for(int i=1; i<=n; i++) {
        while(head<=tail && arr[q[head]].lb>arr[i].rb) {
            head++;
        }
        int t=1;
        if(head<=tail) {
            t=i-q[head-1];
        }
        ans=max(ans, t);
        while(head<=tail && arr[q[tail]].lb<arr[i].lb) {
            tail--;
        }
        tail++;
        q[tail]=i;
    }
    cout << ans;
    return 0;
}