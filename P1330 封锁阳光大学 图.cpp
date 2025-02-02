#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vec[10005];
int color[10005];
int blackCnt, whiteCnt;
bool dfs(int x, int col) {
    color[x]=col;
    if(col==1) {
        blackCnt++;
    } else {
        whiteCnt++;
    }
    for(auto i: vec[x]) {
        if(color[i]==col) {
            return false;
        } else if(color[i]!=0) {
            continue;
        }
        if(!dfs(i, col==1?2:1)) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int res=0;
    for(int i=1; i<=n; i++) {
        if(color[i] == 0) {
            blackCnt=whiteCnt=0;
            if(!dfs(i, 1)) {
                cout<<"Impossible"<<endl;
                return 0;
            }
            res+=min(blackCnt, whiteCnt);        
        }
    }
    cout<<res;
}