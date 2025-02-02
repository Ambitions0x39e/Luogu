#include <iostream>
#include <climits>
using namespace std;
int n;
int d[1000005], f[1000005], q[1000005];
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> d[i];
    }
    int tmp;
    cin >> tmp;
    while(tmp--) {
        int range;
        cin >> range;
        int head=1, tail=1;
        f[1]=0, q[1]=1;
        for(int i=2; i<=n; i++) {
            // cout << "-------" << i << endl;
            while(head<=tail && q[head]+range<i) {
                head++;
            }
            // cout << head << '\t' << tail << '\t';
            if(d[i]>=d[q[head]]) {
                f[i]=f[q[head]]+1;
            } else {
                f[i]=f[q[head]];            
            }
            while(head<=tail && (f[i]<f[q[tail]] || (f[i]==f[q[tail]] && d[i]>=d[q[tail]]))) {
                tail--;
            }
            q[++tail]=i;
        }
        cout << f[n] << endl;
    }
    return 0;
}