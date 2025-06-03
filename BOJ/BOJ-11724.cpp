// Authored by : keyboardmunji
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    vector<bool> vis(n + 1,false);
    for (int i=0 ;i<m;i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        if (vis[i] == true) continue;
        ans++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto t : v[c]) {
                if (vis[t] == true) continue;
                q.push(t);
                vis[t] = true;
            }
        }
    }
    cout << ans;
}
/*
1. 연결 요소의 개수
    - BFS를 몇번 돌렸니 확인 하는 문제인듯.
*/
