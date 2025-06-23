// Authored by : keyboardmunji,
// Created on 2025-06-23.
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
long long MAX = 10000000001;
int n,m,a,b,c;
vector<pair<long long,int>> v[1001];
vector<long long> val(1001,MAX);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i<m;i++) {
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    cin >> a >> b;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    val[a] = 0;
    pq.push({val[a],a});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != val[cur.Y]) continue;
        for (auto t : v[cur.Y]) {
            if (val[t.Y] <= t.X + cur.X) continue;
            val[t.Y] = t.X + cur.X;
            pq.push({val[t.Y],t.Y});
        }
    }
    cout << val[b];
}
/*
문제 : 최소비용 구하기.
    - 정점 a에서 다익스트라 돌려서 b까지의 최소비용 구하기.
*/
