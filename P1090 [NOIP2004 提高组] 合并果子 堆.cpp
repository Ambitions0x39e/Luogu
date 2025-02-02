#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    int ans=0;
    for(int i=0; i<n-1; i++) {
        int top1=pq.top();
        pq.pop();
        int top2=pq.top(); 
        pq.pop();
        ans+=top1+top2;
        pq.push(top1+top2);
    }
    cout<<ans;
}