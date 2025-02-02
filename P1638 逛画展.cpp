#include <iostream>
#include <climits>
using namespace std;

int n, m;
int arr[1000005], q[1000005], cnt[2005];
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    int head=1, tail=0;
    int sum=0;
    int end_lb, end_rb, range=INT_MAX;
    for(int i=1; i<=n; i++) {
        q[++tail]=i;
        cnt[arr[i]]++;
        if(cnt[arr[i]]==1) {
            sum++;
        }
        while(head<=tail && cnt[arr[q[head]]]>1) {
            cnt[arr[q[head]]]--;
            head++;
        }
        if(sum==m) {
            if(range>q[tail]-q[head]+1) {
                end_lb=q[head];
                end_rb=q[tail];
                range=end_rb-end_lb+1;
            }
        }
    }
    cout << end_lb << " " << end_rb;
    return 0;
}