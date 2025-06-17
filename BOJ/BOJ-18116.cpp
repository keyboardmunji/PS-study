// Authored by : keyboardmunji,
// Created on 2025-06-17.
#include <bits/stdc++.h>

using namespace std;

int n,a,b;
char c;
vector<int> p(1000001,-1);
vector<int> rb(1000001,1);

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
    rb[u] += rb[v];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> c;
        if (c == 'I') {
            cin >> a >> b;
            uni (a,b);
        }else {
            cin >> a;
            cout << rb[find(a)] <<'\n';
        }
    }
}
/*
1. 로봇 조립
    - UNION-FIND를 쓰면 각 부품이 어느로봇에 해당하는지를 찾을 수 있음.
    - 그러면 개수는 따로 변수 둬서 해결하면 될듯.
*/
