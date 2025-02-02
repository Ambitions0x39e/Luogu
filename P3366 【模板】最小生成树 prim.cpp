#include <iostream>
#include <queue>
using namespace std;
typedef struct node {
    int v, w;
}NODE;
int n, m, ans;
vector<NODE> graph[5005];
bool visited[5005];
NODE newNode(int v, int w) {
    NODE t;
    t.v=v, t.w=w;
    return t;
}
void prim() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));
    int cnt=0;
    while(!pq.empty() && cnt<n) {
        pair<int, int> t=pq.top();
        pq.pop();
        int weight=t.first, to=t.second;
        if(!visited[to]) {
            visited[to]=1;
            cnt++;
            ans+=weight;
            for(auto i: graph[to]) {
                if(!visited[i.v]) {
                    pq.push(make_pair(i.w, i.v));
                }
            }
        }
    }
    if(cnt<n) {
        cout << "orz" << endl;
    } else {
        cout << ans;
    }
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(newNode(v, w));
        graph[v].push_back(newNode(u, w));
    }
    prim();
    return 0;
}