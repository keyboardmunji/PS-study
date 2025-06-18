// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>

using namespace std;
int n,x,cnt,y,z;
long long sum;
vector<tuple<int,int,int>> v;
vector<int> p(1001,-1);

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

    cin >> n;
    for (int i = 0;i <n;i++) {
        for (int j = 0; j<n;j++) {
            cin >> x;
            if (i == j) continue;
            v.push_back({x,i,j});
        }
    }
    sort(v.begin(),v.end());
    for (int i =0;i<n*n-n;i++) {
        tie(x,y,z) = v[i];
        if (!uni(y,z)) continue;
        cnt++;
        sum = sum + x;
        if (cnt == n - 1) break;
    }
    cout << sum;
}
/*
1. 행성 연결
    - 그저 MST
*/
