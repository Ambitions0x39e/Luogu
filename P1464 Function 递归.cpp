#include <iostream>
using namespace std;

/* 递归 */

typedef long long _int64;
_int64 memory[25][25][25]={0};
_int64 func(_int64 a, _int64 b, _int64 c) {
    if(a<=0 || b<=0 || c<=0) {
        return 1;
    }
    if(a>20 || b>20 || c>20) {
        return func(20, 20, 20);
    }
    if(memory[a][b][c]!=0) {
        return memory[a][b][c];
    }
    if(a<b && b<c) {
        memory[a][b][c]=func(a, b, c-1)+func(a, b-1, c-1)-func(a, b-1, c);
        return memory[a][b][c];
    }
    memory[a][b][c]=func(a-1, b, c)+func(a-1, b-1, c)+func(a-1, b, c-1)-func(a-1, b-1, c-1);
    return memory[a][b][c];
}
int main() {
    while(1) {
        _int64 i, j, k;
        cin >> i >> j >> k;
        if(i==-1 && j==-1 && k==-1) {
            break;
        }
        printf("w(%lld, %lld, %lld) = %lld\n", i, j, k, func(i, j, k));
    }
    return 0;
}