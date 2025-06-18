// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>
using namespace std;

int n,m,k,a,b,c;
vector<int> p(1001,-1);
vector<tuple<int,int,int>> g;
bool el[1001],chk[1001];

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
    if (el[v] == true)
        el[u] = true;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i =0;i<k;i++) {
        cin >> a;
        el[a] = true;
        chk[a] = true;
    }
    for (int i =0; i<m;i++) {
        cin >> a >> b >>c;
        g.push_back({c,a,b});
    }
    sort(g.begin(),g.end());
    int cnt = 0,sum = 0;
    for (int i =0;i<m;i++) {
        tie(a,b,c) = g[i];
        if (find(b) == find(c) || (el[find(c)] == true && el[find(b)] == true)) continue;
        uni(b,c);
        sum += a;
        if (chk[find(b)] == false && el[find(b)] == true) {
            cnt++;
            chk[find(b)] = true;
        }
        if (chk[find(c)] == false && el[find(c)] == true) {
            cnt++;
            chk[find(c)] = true;
        }
        if (cnt == n - k)
            break;
    }
    cout << sum;
}
/*
1. 전기가 부족해
    - mst를 구할 때 확인 하는 정점이 발전소인 경우 다른 정점이 발전소이거나, 이미 집합에 속해 있으면 pass하면 될듯.
*/
