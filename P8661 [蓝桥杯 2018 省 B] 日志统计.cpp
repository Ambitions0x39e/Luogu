#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node {
    int time, topic;
    bool operator <(const struct node & t) const {
        if(topic==t.topic) {
            return time<t.time;
        } else {
            return topic<t.topic;
        }
    }
}NODE;
NODE arr[100005];
int n, d, k;
void calc(int x, int y) {
    int j=x;
    for(int i=x; i<=y; i++) {
        while(j<=y && arr[j].time<arr[i].time+d) {
            j++;
        }
        if((j-i)>=k) {
            cout << arr[i].topic << endl;
            return ;
        }
    }
    return ;
}
int main () {
    cin >> n >> d >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].time >> arr[i].topic;
    }
    sort(arr+1, arr+n+1);
    int start=1;
    while(start<=n) {
        int j=start;
        while(j<=n && arr[j].topic==arr[start].topic) {
            j++;
        }
        calc(start, j-1);
        start=j;
    }
    return 0;
}