#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#define chr(x) ((int)(x-'A'))
#define ord(x) ((char)(x+'A'))
using namespace std;
/*
    Sorted sequence cannot be determined.  din more than 1 is 0
*/
int n, m; 
vector<int> graph[30];
int din[30];
bool vis[30];
bool check_consistency(int x) { // Check if there is loop in graph starting form X
    queue<int> tmp;
    memset(vis, false, sizeof(vis));
    tmp.push(x);
    while(!tmp.empty()) {
        int now=tmp.front();
        tmp.pop();
        if(vis[now]) return false;
        vis[now]=true;
        for(int i=0; i<graph[now].size(); i++) {
            tmp.push(graph[now][i]);
        }
    }
    return true;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        string tmp;
        cin >> tmp;
        char ch1=tmp[0],ch2=tmp[2];
        graph[chr(ch1)].push_back(chr(ch2));
        din[chr(ch2)]++;
        /* At an instance there is no part where din=0*/
        if(check_consistency(chr(ch1))==false) {
            cout << "Inconsistency found after " << i+1 << " relations." << endl;
            return 0;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++) { // Push into queue and check
        if(din[i]==0) {
            q.push(i);
        }
    }
    if(q.size()>1) {
        cout << "Sorted sequence cannot be determined." << endl;
        return 0;
    }
    queue<char> RESULT;
    while(!q.empty()) {
        int now=q.front();
        q.pop();
        RESULT.push(ord(now));
        for(auto i: graph[now]) {
            din[i]--;
            if(din[i]==0) {
                q.push(i);
            }
        }
    }
    cout << "Sorted sequence determined after " << n << " relations: ";
    while(!RESULT.empty()) {
        cout << RESULT.front();
        RESULT.pop();
    }
    cout << ".";
    return 0;
}