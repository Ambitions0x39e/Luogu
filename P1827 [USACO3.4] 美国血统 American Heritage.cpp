#include <iostream>
#include <string>
using namespace std;
string a, b;
void find(int xlb, int xrb, int ylb, int yrb) {
    if(xlb > xrb || ylb > yrb) return;
    int pos=a.find(b[ylb]);
    find(xlb, pos-1, ylb+1, ylb+pos-xlb);
    find(pos+1, xrb, ylb+pos-xlb+1, yrb);
    cout << a[pos];
}
int main() {
    cin >> a >> b;
    find(0, a.length()-1, 0, a.length()-1);
    return 0;
}