#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/* 堆 */

priority_queue<int > q;

int arr1[100005], arr2[100005], ans[100005];
int main() {
    int n;  
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }
    for(int i=0; i<n; i++) {
        cin >> arr2[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(q.size()<n) {
                q.push(arr1[i]+arr2[j]);
            } else {
                if(q.top()>arr1[i]+arr2[j]) {
                    q.pop();
                    q.push(arr1[i]+arr2[j]);
                } else {
                    break; // 单调不降子序列，当前如果大了后续肯定不会更小，剪枝
                }
            }
        }
    }
    int end=0; 
    while(!q.empty()) {
        ans[end++]=q.top();
        q.pop();
    }
    for(int i=end-1; i>=0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}