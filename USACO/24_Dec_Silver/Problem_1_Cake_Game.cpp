#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> vec(n);
        deque<long long> dq;
        for (int i=0; i<n; i++) {
            cin >> vec[i]; 
            dq.push_back(vec[i]);
        }
        long long bessieSum, elsieSum;
        bessieSum=elsieSum=0;
        while (dq.size()>1) {
            if(dq.size()==2) {
                cout << dq.front() + dq.back() << ' ' << elsieSum << endl;
            }
            int l1, l2, r1, r2;
            l1=dq.front(); dq.pop_front(); l2=dq.front(); dq.pop_front();
            r1=dq.back(); dq.pop_back(); r2=dq.back(); dq.pop_back();
            int lSum=l1+l2, rSum=r1+r2;
            if(lSum<rSum) {
                dq.push_front(lSum);
                if(dq.front()<r1) {
                    elsieSum+=r1; 
                    dq.push_back(r2);
                } else {
                    elsieSum+=dq.front();
                    dq.pop_front();
                    dq.push_back(r2);
                    dq.push_back(r1);
                }
            } else {
                dq.push_back(rSum);
                if(dq.back()<l1) {
                    elsieSum+=l1;
                    dq.push_front(l2);
                } else {
                    elsieSum+=dq.back();
                    dq.pop_back();
                    dq.push_front(l2);
                    dq.push_back(l1);
                }
            }
        }
        // cout << dq.front() << elsieSum << endl; 
    }
}