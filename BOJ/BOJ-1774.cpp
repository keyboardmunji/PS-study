// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m,a,b;
double x,y,sum;
vector<int> p(1001,-1);
vector<tuple<double,int,int>> g;
vector<pair<long long,long long>> point(1001);

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
    for (int i = 1; i <= n;i++) {
        cin >> x >> y;
        point[i] = {x,y};
    }
    for (int i = 1;i<=n;i++)
        for (int j = i+1 ;j <= n;j++)
            g.push_back({sqrt((point[i].X - point[j].X) * (point[i].X - point[j].X) + (point[i].Y - point[j].Y) * (point[i].Y - point[j].Y)), i, j});
    sort(g.begin(),g.end());
    int cnt1 = 0,cnt2 = 0;
    for (int i = 0; i<m;i++) {
        cin >> x >> y;
        uni(x,y);
    }
    for (int i = 1; i<=n;i++) {
        if (p[i] < -1) cnt1++;
        if (p[i] != -1) cnt2++;
    }
    int cnt = cnt2 - cnt1;
    for (int i = 0; i < g.size();i++) {
        tie(x,a,b) = g[i];
        if (!uni(a,b)) continue;
        if (cnt == n - 1) break;
        cnt++;
        sum += x;
    }
    cout << fixed << setprecision(2) << sum;
}
/*
1. 우주신과의 교감
    - 빵상? 빵상빵상?
    - O(n^2)으로 간선들을 추가한 후 mst를 구한다.
*/
