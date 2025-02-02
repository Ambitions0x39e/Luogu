#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[100005];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int maxV=0;
    for(int i=1; i<=n; i++) {
        maxV=max(maxV, (int)graph[i].size());
    }
    cout << maxV+1 << endl;
    return 0;
}