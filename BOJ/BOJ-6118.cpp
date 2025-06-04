// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,mx,idx,cnt;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<int> dist(n+1,-1);
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (auto t: v[c]) {
            if (dist[t] != -1) continue;
            dist[t] = dist[c] + 1;
            q.push(t);
            if (mx < dist[t]) {
                mx = dist[t];
                idx = t;
                cnt = 1;
            }else if (mx == dist[t]) {
                cnt++;
                if (idx > t)
                    idx = t;
            }
        }
    }
    cout << idx <<' ' << *max_element(dist.begin(), dist.end()) << ' ' << cnt;
}
/*
1. 숨바꼭질
    - bfs를 돌려서 노드 1번부터의 거리를 구해서 해결함.
*/
