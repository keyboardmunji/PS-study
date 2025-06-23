// Authored by : keyboardmunji,
// Created on 2025-06-23.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m,k,u,v,c;
vector<pair<int,int>> adj[100001];
vector<long long> val(100001,50000000001);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i<m;i++) {
        cin >> u >> v >> c;
        adj[v].push_back({c,u});
    }
    for (int i = 0;i<k;i++) {
        cin >> u;
        adj[0].push_back({0,u});
    }
    val[0] = 0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({val[0],0});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != val[cur.Y]) continue;
        for (auto t : adj[cur.Y]) {
            if (val[t.Y] <= cur.X + t.X) continue;
            val[t.Y] = cur.X + t.X;
            pq.push({val[t.Y],t.Y});
        }
    }
    long long idx = 1, maax = val[1];
    for (int i = 2; i<=n;i++) {
        if (maax < val[i]) {
            idx = i;
            maax = val[i];
        }
    }
    cout << idx <<'\n' << maax;
}
/*
문제 : 면접 보는 승범이네
    - 모든 면접장에서 다익스트라를 돌리기엔 문제가 있음. -> 따라서 면접장을 하나의
    - 단, 간선은 뒤집어 줘야한다는 걸 주의하자.
*/
