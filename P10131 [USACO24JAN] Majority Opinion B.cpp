#include <iostream>
#include <cstring>
using namespace std;

int arr[200005];
bool available[200005];
int main() {
    int x;
    cin >> x;
    while(x--) {
        int n;
        cin >> n;
        memset(arr, 0, sizeof(arr));
        memset(available, 0, sizeof(available));
        for(int i=1; i<=n; i++) {
            cin >> arr[i];
        }
        bool has_result=false;
        for(int i=2; i<=n; i++) {
            if (arr[i]==arr[i-1] || arr[i]==arr[i-2]) {
                available[arr[i]]=true;
                has_result=true;
            }
        }
        if (has_result==false) {
            cout << -1;
        } else {
            for(int i=1; i<=n; i++) {
                if (available[i]) {
                    cout << i << ' ';
                    available[i]=false;
                }
            }
        }
        cout << endl;
    }
    return 0;
}