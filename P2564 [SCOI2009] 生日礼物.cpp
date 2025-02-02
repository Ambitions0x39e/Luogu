#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
typedef struct node {
    int position, type;
    bool operator <(const struct node & t) const {
        return position < t.position;
    }
}NODE;
NODE arr[1000005];
int cnt[65];
queue<NODE> q;
int n, k;
int main() {
    cin >> n >> k;
    int x=1;
    for(int i=1; i<=k; i++) {
        int temp;
        cin >> temp;
        for(int j=0; j<temp; j++) {
            cin >> arr[x].position;
            arr[x].type=i;
            x++;
        }
    }
    sort(arr+1, arr+1+n);
    int total=0, result=INT_MAX;
    for(int i=1; i<=n; i++) {
        if(cnt[arr[i].type]==0) {
            total++;
        }
        cnt[arr[i].type]++;
        q.push(arr[i]);
        while(!q.empty() && cnt[q.front().type]>1) {
            cnt[q.front().type]--;
            q.pop();
        }
        if(total==k) {
            // cout << arr[i].position << '\t' << q.front().position << endl;
            result=min(result, arr[i].position-q.front().position);
        }
    }
    cout << result << endl;
    return 0;
}