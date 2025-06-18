// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,z;
vector<tuple<int,int,int>> g;
vector<int> p(100001,-1);

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;
    if (p[u] > p[v])
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
    for (int i = 0;i<m;i++) {
        cin >> x >> y >> z;
        g.push_back({z,x,y});
    }
    sort(g.begin(),g.end());
    int cnt = 0,sum = 0;
    for (int i = 0;i < m;i++) {
        tie(x,y,z) = g[i];
        if (!uni(y,z)) continue;
        if (cnt == n - 2) break;
        cnt++;
        sum += x;
    }
    cout << sum;
}
/*
1. 도시 분할 계획
    - 경로가 존재한다 == 같은 집합이다.
    - 그러면 MST 구한 다음 그 MST내에서 가장 큰 간선을 제거하면 되는 거 아님?
    - 즉, 크루스칼 MST는 n-1일때 그만 두는데, n-2일때 그만 두면 되잖아.
*/
