#include <iostream>
#include <algorithm>
using namespace std;
typedef struct record {
	int p, m, t;
}RECORD;
RECORD arr[1100];
int milk[51][51], map[51][51]; 
int sumDrink[51]; 
int n, m, d, s, res;
int main()
{
	cin >> n >> m >> d >> s;
    for (int i=1; i<=d; i++) {
        cin >> arr[i].p >> arr[i].m >> arr[i].t;
        map[arr[i].m][arr[i].p]=1;
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            sumDrink[i]+=map[i][j];
        }
    }
    for (int i=1; i<=s; i++) {
        int p, t;
        cin >> p >> t;
        for (int j=1; j<=d; j++) {
            if (p==arr[j].p && arr[j].t<t) {
                milk[arr[j].m][p]=1;
            }
        }
    }
    for(int i=1; i<=m; i++) {
        int ans=0;
        for (int j=1; j<=n; j++) {
            ans+=milk[i][j];
        }
        if (ans==s) {
            res=max(res, sumDrink[i]);
        }
    }
	cout << res << endl;
	return 0;
}