// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,m,p,x,y;
int party[51];
bool rp[51];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    vector<vector<int>> v(n+1);
    for (int i =0; i<p;i++) {
        cin >> x;
        rp[x] = true;
    }
    for (int i =0;i < m; i++) {
        cin >> x;
        for (int j = 0;j<x;j++) {
            cin >> y;
            if (j == 0) {
                party[i] = y;
            }
            else {
                v[party[i]].push_back(y);
                v[y].push_back(party[i]);
            }
        }
    }
    for (int i = 1;i < 51;i++) {
        if (rp[i] == false) continue;
        queue<int> q;
        vector<bool> vis(n+1,false);
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto t : v[c]) {
                if (vis[t] == true || rp[t] == true) continue;
                vis[t] = true;
                rp[t] = true;
                q.push(t);
            }
        }
    }
    int cnt =0;
    for (int i = 0;i<m;i++) {
        if (rp[party[i]] == false) cnt++;
    }
    cout << cnt;
}
/*
1. 거짓말
    - 간선이 중복이 되는 그래프를 만들거임.
    - 일단, 파티 안에서 첫번째 수와 나머지 모두를 연결 시킴.
    - 그 다음 진실을 아는 애들을 기준으로 bfs를 돌리면 됨.
    - 그러면 진실을 말해야하는 노드들이 특정됨.
    - 그다음 파티의 첫번째 인물이 진실을 말해야하는 노드인지 아닌지만 확인하면 종료.
*/
