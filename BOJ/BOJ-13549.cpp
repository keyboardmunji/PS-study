// Authored by : keyboardmunji
// Created on 2025-08-02.
#include <bits/stdc++.h>
using namespace std;

int a,b;
int vis[100001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    fill(vis, vis+100001, 100001);
    queue<int> q;
    q.push(a);
    vis[a] = 0;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        if (c - 1 >= 0 && vis[c-1] > vis[c] + 1) {
            q.push(c-1);
            vis[c-1] = vis[c] + 1;
        }
        if (c + 1 <= 100000 && vis[c + 1] > vis[c] + 1) {
            q.push(c+1);
            vis[c + 1] = vis[c] + 1;
        }
        if (c * 2 <= 100000 && vis[c * 2] > vis[c]) {
            q.push(c*2);
            vis[c * 2] = min(vis[c*2],vis[c]);
        }
    }
    cout << vis[b];
}
/*
1. 숨바꼭질 3
    - 1차원 bfs
*/