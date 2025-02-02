#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* 字符串 */

typedef struct team {
    public:
        string name;
        int ttl=0;
        int win=0;
        int cnt=0;
}_team;
_team arr[55];
int n;
void split_name(string orig, string & name1, string & name2) {
    int bk1=orig.find('-');
    name1=orig.substr(0, bk1);
    name2=orig.substr(bk1+1, orig.length()-bk1-1);
}
int search(string src) {
    for(int i=0; i<n; i++) {
        if(arr[i].name==src) {
            return i;
        }
    }
    return -1;
}
bool sort_team(const _team &a, const _team &b) {
    if(a.ttl==b.ttl) {
        if(a.win==b.win) {
            return a.cnt>b.cnt;
        }
        return a.win>b.win;
    }  
    return a.ttl>b.ttl;
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].name;
    }
    for(int i=0; i<n*(n-1)/2; i++) {
        string orig, name1, name2;
        cin >> orig;
        int num1, num2;
        scanf("%d:%d", &num1, &num2);
        split_name(orig, name1, name2);
        int pos1=search(name1), pos2=search(name2);
        if(num1>num2) {
            arr[pos1].ttl+=3;
        } else if (num1<num2) {
            arr[pos2].ttl+=3;
        } else {
            arr[pos1].ttl++;
            arr[pos2].ttl++;
        }
        arr[pos1].win+=num1-num2;
        arr[pos2].win+=num2-num1;
        arr[pos1].cnt+=num1;
        arr[pos2].cnt+=num2;
    }
    sort(arr, arr+n, sort_team);
    string top_half[35];
    for(int i=0; i<n/2; i++) {
        top_half[i]=arr[i].name;
    }
    sort(top_half, top_half+n/2);
    for(int i=0; i<n/2; i++) {
        cout<<top_half[i]<<endl;
    }
}
