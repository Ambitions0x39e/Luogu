#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long double ld;
typedef struct node {
    ld x, y, time;
    bool operator < (const struct node & t)const {
        return time<t.time;
    }
}NODE;
NODE arr1[100005], arr2[100005];
ld calc(ld x1, ld y1, ld x2, ld y2) {
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int g, n;
int main() {
    cin >> g >> n;
    for(int i=0; i<g; i++) {
        cin >> arr1[i].x >> arr1[i].y >> arr1[i].time;
    }
    for(int i=0; i<n; i++) {
        cin >> arr2[i].x >> arr2[i].y >> arr2[i].time;
    }
    sort(arr1, arr1+g);
    sort(arr2, arr2+n);
    int pos=0, ans=0;
    for(int i=0; i<n; i++) {
        while(pos<g && arr1[pos].time<arr2[i].time) {
            pos++;
        }
        bool flag=false;
        if(pos<g && (calc(arr1[pos].x, arr1[pos].y, arr2[i].x, arr2[i].y)>pow(arr2[i].time-arr1[pos].time, 2))) {
            flag=true;
        }
        if(pos>0 && (calc(arr1[pos-1].x, arr1[pos-1].y, arr2[i].x, arr2[i].y)>pow(arr2[i].time-arr1[pos-1].time, 2))) {
            flag=true; 
        }
        ans+=flag;
    }
    cout << ans;
    return 0;
}