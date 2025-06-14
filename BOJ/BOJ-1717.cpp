// Authored by : keyboardmunji,
// Created on 2025-06-14.
#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,z;
vector<int> p(1000001,-1);

int find(int x) {
    if (p[x] < 0)
        return x;
    return  p[x] = find(p[x]);
}

bool uni(int u,int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;
    if (p[v] < p[u])
        swap(u,v);
    if (p[u] == p[v])
        p[u]--;
    p[v] = u;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0 ;i <m;i++) {
        cin >> x >> y>> z;
        if (x == 0)
            uni(y,z);
        else {
            if (find(y) == find(z))
                cout << "YES" <<'\n';
            else
                cout << "NO" << '\n';
        }
    }
}
/*
1. 집합의 표현
    - 유니온 파인드로 집합 묶어주고, find
*/
