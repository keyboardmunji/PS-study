// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int k,v,e,x,y;

void bfs() {
    vector<vector<int>> ve(v+1);
    vector<int> vis(v+1,0);
    for (int i = 0; i<e;i++) {
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    queue<int> q;
    for (int i = 1;i<v;i++) {
        if (vis[i] != 0) continue;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto t : ve[c]) {
                if (vis[t] == -vis[c] || t == c) continue;
                if (vis[t] == vis[c]) {
                    cout << "NO\n";
                    return;
                }
                q.push(t);
                vis[t] = -vis[c];
            }
        }
    }
    cout << "YES\n";
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    while (k--) {
        cin >> v >> e;
        bfs();
    }
}
/*
1. 이분 그래프
    - 2개의 그래프로 나누었을 때, 모든 간선 지우기 -> 간선으로 주어진 노드들은 다른 그래프에 속해야함.
    - 이게 만족하지 않으면 이분그래프가 아님.
    - 그러면 bfs를 돌리자. 1번 노드 부터 bfs를 돌리는데, 인접해 있으면 -1을 넣던가 1을 넣으면 되지.
    - 그러면 일단 자기 자신을 가르키는 간선은? -> 무시하기.
    - 그래프가 단절되어 있다면? -> 아무곳에나 넣어도 됨.
*/
