#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/* 二分答案 堆 */

int arr[100005];
int n, tMax;
bool check(int mid) {
    int tSum=0, last=0;
    priority_queue<int, vector<int>, greater<int> >q;
    for(int i=0; i<mid; i++) {
        q.push(arr[i]); // 初始窗口
    }
    for(int i=mid; i<n; i++) {
        tSum+=q.top()-last;// 此次的消耗时间于上次的相关，例如0-4, 4-5
        if(tSum>tMax) {
            return false;
        }
        last=q.top();
        q.pop();
        q.push(arr[i]+last);// 推入新的，从当前使用的时间开始
    }
    for(int i=mid-1; i>=0; i--) {
        tSum+=q.top()-last;
        if(tSum>tMax) {
            return false;
        }
        last=q.top();
        q.pop();
    }
    return tSum<=tMax;
}
int main() {
    cin >> n >> tMax;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int lb=0, rb=100005, mid;
    int ans=n;
    while(lb<rb) {
        mid=(lb+rb)/2;
        if(check(mid)) {
            ans=mid;
            rb=mid;
        } else {
            lb=mid+1;
        }
    }
    cout<<ans;
    return 0;
}