#include <iostream>
#include <string>
#include <queue>
using namespace std;

priority_queue<string, vector<string>, greater<string> > pq;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pq.push(s);
	}
    string pref;
    cin >> pref;
	while (!pq.empty()) {
		if(pq.top().find(pref)==0) {
            cout<<pq.top()<<endl;
        }
        pq.pop();
	}
	return 0;
}