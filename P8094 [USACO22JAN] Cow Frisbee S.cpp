#include <iostream>
#include <stack>
using namespace std;

long long ans, n;
long long arr[300005];
stack<int> s;
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            ans+=i-s.top()+1;
            s.pop();
        }
        if(!s.empty()) {
            ans+=i-s.top()+1;
        }
        s.push(i);
    }
    cout << ans;
    return 0;
}