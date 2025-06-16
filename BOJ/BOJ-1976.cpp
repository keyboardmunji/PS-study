// Authored by : keyboardmunji,
// Created on 2025-06-12.
#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,z;
vector<int> p(201,-1);

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
        swap(u,v);
    if (p[u] == p[v])
        p[u]--;
    p[v] = u;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1 ;i <= n;i++) {
        for (int j = 1; j<=n;j++) {
            cin >> x;
            if (x == 0) continue;
            uni(i,j);
        }
    }
    int ch;
    for (int i = 0;i < m;i++) {
        cin >> x;
        if (i == 0)
            ch = find(x);
        else if (ch != find(x)) {
            cout <<"NO";
            return 0;
        }
    }
    cout <<"YES";
}
/*
1. 여행가자
    - 그래프 탐색으로 쉽게 풀 수 있지만, 한번 유니온 파인드로 풀어보자
    - 뒤에 1일때 union을 해주고, find가 다 같은지 확인하면 될듯.
*/
