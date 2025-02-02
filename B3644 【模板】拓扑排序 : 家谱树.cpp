#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int arr[105];
vector<int> vec[105];
queue<int> q;
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        int a, cnt=0;
        while(true) {
            cin >> a;
            if(a == 0) {
                break;
            }
            vec[i].push_back(a);
            arr[a]++;
        }
    }
    for(int i=1; i<=n; i++) {
        if(arr[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int top=q.front();
        q.pop();
        cout << top << ' ';
        for(auto i: vec[top]) {
            arr[i]--;
            if(arr[i]==0) {
                q.push(i);
            }
        }
    }
    return 0;
}