#include <iostream>
#include <cstring>
using namespace std;
int arr[2048][2048], n, s;
int main() {
    cin >> n;
    if(n==1) {
        printf("1 1");
        return 0;
    }
    for(int i=1; i<=n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            arr[i][j+1]=str[j]=='L'?1:0;
        }
    }
    for(int i=1; i<=n; i++){
        if(arr[i][1]) {
            for(int j=1; j<=n; j++) {
                arr[i][j]^=1;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(arr[1][i]) {
            for(int j=1; j<=n; j++) {   
                arr[j][i]^=1;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        for(int j=2; j<=n; j++) {
            s+=arr[i][j];
        }
    }
    if(s==(n-1)*(n-1)) {
        if(n==2) {
            printf("-1");
        } else {
            printf("1 1");
        }
        return 0;
    }
    if (s==1) {
        for(int i=2; i<=n; i++) {
            for(int j=2; j<=n; j++) {
                if(arr[i][j]) {
                    printf("%d %d", i, j);
                    return 0;
                }
            }
        }
    }
    if (s==n-1) {
        int x=0;
        for(int i=1; i<=n; i++) {
            x=0;
            for(int j=1; j<=n; j++) {
                x+=arr[i][j];
            }
            if(x==s) {
                printf("%d 1", i);
                return 0;
            }
        }
        for(int i=1; i<=n; i++) {
            x=0; 
            for(int j=1; j<=n; j++) {
                x+=arr[j][i];
            }
            if(x==s) {
                printf("1 %d", i);
                return 0;
            }
        }
    }
    return 0;
}