#include <iostream>
#include <stack>
using namespace std;

int n;
long long arr[80005];
stack<long long> s;
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    long long ans=0;
    for(int i=1; i<=n; i++) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        ans+=s.size(); // 在推出栈顶比我小的数字后，剩余数量永远为比我大的数字
        s.push(arr[i]);
    }   
    cout << ans;
    return 0;
}