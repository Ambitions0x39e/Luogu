#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
using namespace std;

/* 二重并查集 */

int n1, n2, p1, p2;
int ancestor_men[10005], ancestor_women[10005];
int get_ancestor_men(int x) {
    if(ancestor_men[x]==x) {
        return x;
    } else {
        return ancestor_men[x]=get_ancestor_men(ancestor_men[x]);
    }
}
int get_ancestor_women(int x) {
    if(ancestor_women[x]==x) {
        return x;
    } else {
        return ancestor_women[x]=get_ancestor_women(ancestor_women[x]);
    }
}
void union_set_men(int x, int y) {
    ancestor_men[get_ancestor_men(x)]=get_ancestor_men(y);
}
void union_set_women(int x, int y) {
    ancestor_women[get_ancestor_women(x)]=get_ancestor_women(y);
}

int main() {
    cin >> n1 >> n2 >> p1 >> p2;
    for(int i=1; i<=n1; i++) {
        ancestor_men[i]=i;
    }
    for(int i=1; i<=n2; i++) {
        ancestor_women[i]=i;
    }
    for(int i=1; i<=p1; i++) {
        int x, y;
        cin >> x >> y;
        union_set_men(x, y);
    }
    for(int i=1; i<=p2; i++) {
        int x, y;
        cin >> x >> y;
        union_set_women(-x, -y);
    }
    int t1=0, t2=0;
    for(int i=1; i<=n1; i++) {
        if(get_ancestor_men(i)==get_ancestor_men(1)) {
            t1++;
        }
    }
    for(int i=1; i<=n2; i++) {
        if(get_ancestor_women(i)==get_ancestor_women(1)) {
            t2++;
        }
    }
    cout<<min(t1, t2);
}