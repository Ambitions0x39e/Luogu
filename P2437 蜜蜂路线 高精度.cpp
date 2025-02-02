#include <iostream>
#include <string>
using namespace std;

/* 高精度 数学 */

typedef class bignumber {
public:
    int Number[1024]={0};
    int number_length=0;

public:
    void formatting() {
        for(int i=0; i<number_length; i++) {
            Number[i+1]+=Number[i]/10;
            Number[i]%=10;
        }
        if(Number[number_length]!=0) {
            number_length++;
        }
    }
    void init_int32(int src) {
        while(src!=0) {
            Number[number_length++]=src%10;
            src/=10;
        }
    }
    void output() {
        for(int i=number_length-1; i>=0; i--) {
            cout<<Number[i];
        }
        cout<<endl;
    }
}BigNumber;
BigNumber operator +(const BigNumber a, const BigNumber b) {
    BigNumber c;
    c.number_length=max(a.number_length, b.number_length);
    for(int i=0; i<c.number_length; i++) {
        c.Number[i]=a.Number[i]+b.Number[i];
        // cout<<a.Number[i]<<' '<<b.Number[i]<<endl;
    }
    c.formatting();
    return c;
}
int main() {
    BigNumber a, b;
    a.init_int32(1);
    b.init_int32(1);

    int lb, rb;
    cin >> lb >> rb;
    int targ=rb-lb-1;
    while(targ) {
        targ--;
        BigNumber c=a+b;
        a=b;
        b=c;
        // c.output();
    }
    b.output();
    return 0;
}