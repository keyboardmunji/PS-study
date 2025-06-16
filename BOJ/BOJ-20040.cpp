// Authored by : keyboardmunji,
// Created on 2025-06-16.
#include <bits/stdc++.h>

using namespace std;
int n,m,x,y;
vector<int> p(500001,-1);

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
        swap(u, v);
    if (p[u] == p[v])
        p[u]--;
    p[v] = u;
    return true;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i<= m;i++) {
        cin >> x >> y;
        if (!uni(x,y)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}
/*
1. 사이클 게임
    - 사이클이 생겼다는 것을 어떻게 알 수 있을까?
    - 매번 BFS를 돌리는 것은 시간복잡도가 오버될듯.
    - 아 유니온 파인드로 해결할 수 있을 듯. 루트가 같으면 이미 같은 집합이라는 의미인데, 거기서 간선을 연결 하려고 하면 사이클이 생김.
*/
