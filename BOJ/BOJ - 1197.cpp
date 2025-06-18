// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>

using namespace std;
int v,e,x,y,z,val,cnt;
vector<tuple<int,int,int>> g;
vector<int> p(10001,-1);

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

void uni(int u,int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;
    if (p[u] > p[v])
        swap(u, v);
    if (p[u] == p[v])
        p[u]--;
    p[v] = u;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> z;
        g.push_back({z,x,y});
    }
    sort(g.begin(),g.end());
    for (int i = 0; i<e;i++) {
        tie(x,y,z) = g[i];
        if (find(y) == find(z)) continue;
        uni(y,z);
        val += x;
        cnt++;
        if (cnt == v-1) break;
    }
    cout << val;

}
/*
1. 최소 스패닝 트리
    - 크루스칼 알고리즘 이용해서 해보기.
*/
