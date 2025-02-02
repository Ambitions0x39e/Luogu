#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr1[500005], arr2[500005], prefix[500005], suffix[500005];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> arr1[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> arr2[i];
    }
    for(int i=0; i<n; i++) {
        prefix[i+1]=prefix[i]+(arr1[i]==arr2[i]);
    }
    for(int i=n-1; i>=0; i--) {
        suffix[i]=suffix[i+1]+(arr1[i]==arr2[i]);
    }
    // for(int i=0; i<n; i++) { cout << prefix[i] << " "; } cout << endl; 
    // for(int i=0; i<n; i++) {cout << suffix[i] << " "; } cout << endl;
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int tmp=prefix[i]+suffix[j+1];
            for(int k=i; k<=j; k++) {
                // printf("%d %d %d %d %d\n", i, j, k, arr1[k], arr2[j-(k-i)]);
                if(arr1[k]==arr2[j-(k-i)]) {
                    tmp++;
                }
            }
            ans+=tmp;
        }
    }
    cout << ans << endl;
    return 0;
}