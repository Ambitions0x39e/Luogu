#include <iostream>
using namespace std;
typedef struct node {
    int lt, rt;
}NODE;
NODE arr[100005];
int n;
void DLR(int x) {
    if(x==0) return;
    cout << x << " ";
    DLR(arr[x].lt);
    DLR(arr[x].rt);
}
void LDR(int x) {
    if(x==0) return;
    LDR(arr[x].lt);
    cout << x << " ";
    LDR(arr[x].rt);
}
void LRD(int x) {
    if(x==0) return;
    LRD(arr[x].lt);
    LRD(arr[x].rt);
    cout << x << " ";
}
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i].lt >> arr[i].rt;
    }
    DLR(1); 
    cout << endl;
    LDR(1);
    cout << endl;
    LRD(1);
    return 0;
}