#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
vector<int> graph[105];
int peopleNumber[105];
bool vis[105];
int dist[105]; // Dist to each point
int n;
void dijkstra(int startPoint) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(startPoint, 0)); // Pair<Point, Dist_To_Pt>
    while(!pq.empty()) {
        pair<int, int> tmp = pq.top();
        pq.pop();
        dist[tmp.first]=tmp.second;
        vis[tmp.first]=true;
        for(auto i: graph[tmp.first]) {
            if(vis[i]) {
                continue;
            }
            pq.push(make_pair(i, tmp.second+1));
        }
    }
}
int calculate_distance() {
    int ans=0;
    for(int i=1; i<=n; i++) {
        ans+=dist[i]*peopleNumber[i];
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        int lb, rb;
        cin >> peopleNumber[i] >> lb >> rb;
        if(lb!=0) {
            graph[i].push_back(lb);
            graph[lb].push_back(i);
        } 
        if(rb!=0) {
            graph[i].push_back(rb);
            graph[rb].push_back(i);
        }
    }
    int ans=INT_MAX;
    for(int i=1; i<=n; i++) {
        memset(dist, 0, sizeof(dist));
        memset(vis, false, sizeof(vis));
        dijkstra(i);
        ans=min(ans, calculate_distance());
    }
    cout << ans;
    return 0;
}