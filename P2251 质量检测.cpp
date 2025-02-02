#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1000005], q[1000005];
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    int head=1, tail=0;
    for(int i=1; i<=n; i++) {
        while(head<=tail && q[head]+m<=i) {
            head++;
        }
        while(head<=tail && arr[q[tail]]>arr[i]) {
            tail--;
        }
        q[++tail]=i;
        if(i>=m) {
            cout << arr[q[head]] << endl;
        }
    }

    return 0;
}