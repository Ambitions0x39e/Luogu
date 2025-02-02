#include <iostream>
using namespace std;

int target[100005], current[100005];
int positive[100005], negative[100005];
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> target[i];
    } 
    for (int i=1; i<=n; i++) {
        cin >> current[i];
    }
    for (int i=1; i<=n; i++) {
        int val=target[i]-current[i];
        if(val>0) {
            positive[i]=val;
        } else if (val<0) {
            negative[i]=-val;
        }
    }
    int sum=0;
    for(int i=1; i<=n; i++) {
        if (positive[i]>positive[i-1]) {
            sum+=positive[i]-positive[i-1];
        }
        if (negative[i]>negative[i-1]) {
            sum+=negative[i]-negative[i-1];
        }
    }
    cout << sum << endl;
    return 0;
}