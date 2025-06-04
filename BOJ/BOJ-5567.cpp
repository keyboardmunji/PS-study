// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,ans;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<int> dist(n+1,-1);
    for (int i =0;i <m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (dist[c] == 2) continue;
        for (auto t : v[c]) {
            if (dist[t] != -1) continue;
            q.push(t);
            dist[t] = dist[c] + 1;
            ans++;
        }
    }
    cout << ans;
}
/*
1. 결혼식
    - bfs를 돌리는데, 거리가 2보다 크면 을 vis조건 옆에 추가하면 됨.
*/
