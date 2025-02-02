#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > left_heap; 
priority_queue<int, vector<int>, greater<int> > right_heap; 
int main() {
    int n;
    cin >> n;
    int mid;
    cin >> mid;
    cout << mid << endl;
    int val;
    for(int i=1; i<n; i++) {
        cin >> val;
        if(val>mid) {
            right_heap.push(val);
        } else {
            left_heap.push(val);
        }
        if(!(i%2)) {
            while(left_heap.size()!=right_heap.size()) {
                if(left_heap.size()>right_heap.size()) {
                    right_heap.push(mid);
                    mid=left_heap.top();
                    left_heap.pop();
                } else {
                    left_heap.push(mid);
                    mid=right_heap.top();
                    right_heap.pop();
                }
            }
            cout << mid << endl;
        }
    }
    return 0;
}