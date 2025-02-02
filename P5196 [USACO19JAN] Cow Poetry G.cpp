#include <iostream>
using namespace std;
int arr1[5005], arr2[5005];
long long f[5005], f2[5005][5005];
int ending[30]; 
long long quick_pow(int n, int x) {
    if(x==0) {
        return 1;
    }
    if(x==1) {
        return n;
    }
    long long tmp=quick_pow(n, x/2);
    if(x%2==0) {
        return tmp*tmp%1000000007;
    } else {
        return tmp*tmp%1000000007*n%1000000007;
    }
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr1[i] >> arr2[i];
    }
    for(int i=1; i<=m; i++) {
        char letter;
        cin >> letter;
        ending[letter-'A'+1]++;
    }
    f[0]=1;
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=n; j++) {
            if(i-arr1[j]>=0) {
                f2[i][arr2[j]]=(f2[i][arr2[j]]+f[i-arr1[i]])%1000000007;
                f[i]=(f[i]+f[i-arr1[j]])%1000000007;
            }
        }
    }
    long long res=1;
    for(int i=1; i<=26; i++) {
        if(ending[i]==0) {
            continue;
        }
        long long tmp=0;
        for(int j=1; j<=n; j++) {
            tmp=(tmp+quick_pow(f2[k][j], ending[i]))%1000000007;
        }
        res=res*tmp%1000000007;
    }
    cout << res;
    return 0;
}