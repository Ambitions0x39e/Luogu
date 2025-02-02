#include <iostream>
#include <cstring>
using namespace std;

int arr[1000005], q[1000005], head, tail, n, k;
int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    head=0, tail=1;
    for(int i=1; i<=n; i++) {
        while(head<=tail && arr[i]<=arr[q[tail]]) {
            tail--;
        }
        q[++tail]=i;
        while(head<=tail && i-q[head]>=k) {
            head++;
        }
        if(i>=k) {
            cout << arr[q[head]] << " ";
        }
    }
    cout << endl;
    head=0, tail=1;
    memset(q, 0, sizeof(q));
    for(int i=1; i<=n; i++) {
        while(head<=tail && arr[i]>=arr[q[tail]]) {
            tail--;
        }
        q[++tail]=i;
        while(head<=tail && i-q[head]>=k) {
            head++;
        }
        if(i>=k) {
            cout << arr[q[head]] << " ";
        }
    }
    return 0;
}