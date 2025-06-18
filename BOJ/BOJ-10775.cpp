// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>

using namespace std;
int n,m,x;
vector<int> p(100001,-1);
int id[100001]; // id[i] : i번째 idx가 넣을 수 있는 위치. // 단 루트만 탐색함.

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;
    if (p[u] > p[v])
        swap(u,v);
    if (p[u] == p[v])
        p[u]--;
    p[v] = u;
    id[u] = min(id[u],id[v]);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i<=n;i++)
        id[i] = i;
    for (int i = 1; i<= m;i++) {
        cin >> x;
        int idx = find(x);
        if (id[idx] == 0) {
            cout << i - 1;
            return 0;
        }
        uni(idx,id[idx] - 1);
    }
    cout << n;
}
/*
1. 공항
    - 우선 그리디를 적용해야함. -> 자기 번호에 우선적으로 넣어야 됨.
    - 그 다음 idx - 1과 union을 하면서 idx가 넣을 수 있는 값과, idx - 1이 넣을 수 있는 값 중 적은 값을 루트가 가짐.
    - 그러면 루트에 접근했을 때 -> 넣을 수 있는 위치라는 거지.
*/
