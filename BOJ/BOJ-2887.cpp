// Authored by : keyboardmunji,
// Created on 2025-06-19.
#include <bits/stdc++.h>
using namespace std;

int n,x,y,z;
vector<pair<int,int>> v[3];
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

void func1(int a) {
    sort(v[a].begin(),v[a].end());
    for (int i = 0; i<v[a].size();i++) {
        if (i != 0)
            g.push_back({abs(v[a][i-1].first - v[a][i].first),v[a][i-1].second,v[a][i].second});
        if (i != v[a].size()-1)
            g.push_back({abs(v[a][i].first - v[a][i+1].first),v[a][i].second,v[a][i+1].second});
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i<=n;i++) {
        cin >> x >> y >> z;
        v[0].push_back({x,i});
        v[1].push_back({y,i});
        v[2].push_back({z,i});
    }
    for (int i = 0;i<3;i++)
        func1(i);
    sort(g.begin(),g.end());
    int cnt = 0;
    long long sum =0;
    for (int i =0 ;i<g.size();i++) {
        tie(x,y,z) = g[i];
        if (!uni(y,z)) continue;
        sum += x;
        cnt++;
        if (cnt == n-1) break;
    }
    cout << sum;
}
/*
1. 행성 터널
    - 자기 자신과 가장 가까운 행성을 찾는 방법은 각각 x,y,z로 정렬한 것들에 대해 앞 뒤로 확인해서 확인하면 됨.
    - 그러면 여러개의 쌍이 상호작용하는 것도 사라짐. 즉, 트리가 2개이상 생성되지 않음.
*/
