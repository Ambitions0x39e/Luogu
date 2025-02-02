#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    int n;
    cin >> n;
    while(n--) {
        int op;
        cin >> op;
        if(op==1) {
            int val;
            cin >> val;
            pq.push(val);
        } else if (op==2) {
            cout<<pq.top()<<endl;
        } else if (op==3) {
            pq.pop();
        }
    }
    return 0;
}