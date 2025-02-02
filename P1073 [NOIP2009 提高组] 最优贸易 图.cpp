#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int forwards[100005], backwards[100005], value[100005];
int n, m;
vector<int> forward_graph[100005], backward_graph[100005];
void bfs1() {
    memset(forwards, 0x7f, sizeof(forwards));
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int tmp=q.front();
        q.pop();
        forwards[tmp]=min(forwards[tmp], value[tmp]);
        for(int i=0; i<forward_graph[tmp].size(); i++) {
            if(forwards[tmp] < forwards[forward_graph[tmp][i]]) {
                forwards[forward_graph[tmp][i]]=forwards[tmp];
                q.push(forward_graph[tmp][i]);
            }
        }
    }
//     for(int i=1; i<=n; i++) {
//         cout << forwards[i] << " ";
//     }
}
void bfs2() {
    memset(backwards, 0, sizeof(backwards));
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int tmp=q.front();
        q.pop();
        backwards[tmp]=max(backwards[tmp], value[tmp]);
        for(int i=0; i<backward_graph[tmp].size(); i++) {
            if(backwards[tmp] > backwards[backward_graph[tmp][i]]) {
                backwards[backward_graph[tmp][i]]=backwards[tmp];
                q.push(backward_graph[tmp][i]);
            }
        }
    }
    // for(int i=1; i<=n; i++) {
    //     cout << backwards[i] << " ";
    // }
}
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> value[i];
    }
    for(int i=1; i<=m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(z==1) {
            forward_graph[x].push_back(y);
            backward_graph[y].push_back(x);
        } else {
            forward_graph[x].push_back(y);
            forward_graph[y].push_back(x);
            backward_graph[x].push_back(y);
            backward_graph[y].push_back(x);
        } 
    }  
    bfs1();
    bfs2();
    int res=INT_MIN;
    for(int i=1; i<=n; i++) {
        res=max(res, backwards[i]-forwards[i]);
    }
    cout << res << endl;
    return 0;
} 