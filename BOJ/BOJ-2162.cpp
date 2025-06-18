// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,a1,a2,b1,b2;
vector<int> p(3001,-1);
vector<int> s(3001,1);
vector<tuple<pair<int,int>,pair<int,int>>> v;

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

int ccw(pair<int,int> a, pair<int,int> b,pair<int,int> c) {
    int l = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
    if (l == 0) return 0;
    return (l > 0 ? 1 : -1);
}

int cross(tuple<pair<int,int>,pair<int,int>> a, tuple<pair<int,int>,pair<int,int>> b) {
    int c1 = ccw(get<0>(a),get<1>(a),get<0>(b)) * ccw(get<0>(a),get<1>(a),get<1>(b));
    int c2 = ccw(get<0>(b),get<1>(b),get<0>(a)) * ccw(get<0>(b),get<1>(b),get<1>(a));

    if (c1 == 0 && c2 == 0)
        return !(get<1>(a) < get<0>(b) || get<1>(b) < get<0>(a));
    return c1 <= 0 && c2 <= 0;
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
    s[u] += s[v];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> a1 >> b1 >> a2 >> b2;
        pair<int,int> p1 = {a1,b1};
        pair<int,int> p2 = {a2,b2};
        if (p1 > p2)
            swap(p1,p2);
        v.push_back({p1,p2});
    }
    for (int i = 0;i<n;i++) {
        for (int j = i + 1;j<n;j++) {
            if (find(i) == find(j)) continue;
            if (cross(v[i],v[j]))
                uni(i,j);
        }
    }
    int cnt = 0,mx = 0;
    for (int i =0 ;i <n;i++) {
        if (find(i) == i) {
            cnt++;
            mx = max(mx, s[i]);
        }
    }
    cout << cnt <<'\n' << mx;
}
/*
1. 선분 그룹
    - 선분들을 저장한다. 첫번째 선분를 기준으로 모든 선분에 대해 CCW를 진행한다.
    - 만약 교차한다면 union을 해준다. root가 다를 때만 CCW를 진행하면 된다.
    - union을 저장하면서 size도 따로 받아준다.
*/
