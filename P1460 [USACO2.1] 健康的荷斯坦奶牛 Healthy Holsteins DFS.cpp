#include <iostream>
#include <vector>
using namespace std;

/* dfs */

int n, target[30], m, amounts[20][30], ans_cnt=0;
bool selected[30], dfs_flag=false;
bool answer[30];
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> target[i];
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> amounts[i][j];
        }
    }
    
    return 0;
}