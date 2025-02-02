#include <iostream>
#include <stack>
using namespace std;

int arr[3000005];
int ans[3000005];
stack<int> s;
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=n; i>0; i--) {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            ans[i] = 0;
        } else {
            ans[i]=s.top();
        }
        s.push(i);
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}