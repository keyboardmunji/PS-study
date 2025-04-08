// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
using namespace std;

int n,m,v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> v;
    vector<vector<int>> v1(n+1);
    for (int i =0;i<m;i++) {
        int x,y;
        cin >> x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i =1;i<=n;i++)
        sort(v1[i].begin(),v1[i].end());
    stack<int> s;
    vector<bool> vis(n + 1,0);
    s.push(v);
    while (!s.empty()) {
        int c = s.top(); s.pop();
        if (vis[c]) continue;
        vis[c] = true;
        cout << c <<' ';
        int len = v1[c].size();
        for (int i = len-1 ;i >= 0;i--) {
            if (vis[v1[c][i]]) continue;
            s.push(v1[c][i]);
        }
    }
    cout <<'\n';
    queue<int> q;
    for (int i =0;i<=n;i++) vis[i] = false;
    q.push(v);
    vis[v] = true;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        cout << c <<' ';
        int len = v1[c].size();
        for (int i = 0; i< len;i++) {
            if (vis[v1[c][i]]) continue;
            vis[v1[c][i]] = true;
            q.push(v1[c][i]);
        }
    }
    return 0;
}

/*
 1. 문제그대로 그래프 dfs,bfs탐색
 2. 단, 각각 sort해줘야할듯.
*/