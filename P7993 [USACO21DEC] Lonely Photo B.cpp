#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> G, H;
int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    G.push_back(0);
    H.push_back(0);
    for (int i=0; i<n; i++) {
        if (str[i]=='G') {
            G.push_back(i+1);
        } else {
            H.push_back(i+1);
        }
    }
    long long ans=0;
    for (int i=1; i<G.size(); i++) {
        int lb=G[i]-G[i-1]-1;
        int rb;
        if (i==G.size()-1) {
            rb=n-G[i];
        } else {
            rb=G[i+1]-G[i]-1;
        }
        ans+=max(0, lb-1)+max(0, rb-1)+(long long)lb*rb;
    }
    for (int i=1; i<H.size(); i++) {
        int lb=H[i]-H[i-1]-1;
        int rb;
        if (i==H.size()-1) {
            rb=n-H[i];
        } else {
            rb=H[i+1]-H[i]-1;
        }
        ans+=max(0, lb-1)+max(0, rb-1)+(long long)lb*rb;
    }
    cout << ans;
    return 0;
}