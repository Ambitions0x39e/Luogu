#include <iostream>
using namespace std;
int arr[]={-1, 1, 2, 4, 7, 8, 11, 13, 14};
int main() {
    int n;
    cin >> n;
    cout << arr[n%8]+(n/8)*15 << endl;
    return 0;
}