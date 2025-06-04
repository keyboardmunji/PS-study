// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,cnt;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> g1(n+1); // 큰 것
    vector<vector<int>> g2(n+1); // 작은 것
    for (int i =0;i <m;i++) {
        cin >> x >> y;
        g1[y].push_back(x);
        g2[x].push_back(y);
    }
    for (int i = 1;i<=n;i++) {
        queue<int> q;
        vector<bool> vis(n+1);
        q.push(i);
        vis[i] = true;
        int big = 0;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto t : g1[c]) {
                if (vis[t]) continue;
                vis[t] = true;
                q.push(t);
                big++;
            }
        }
        q.push(i);
        fill(vis.begin(),vis.end(),false);
        vis[i] = true;
        int small = 0;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto t : g2[c]) {
                if (vis[t]) continue;
                vis[t] = true;
                q.push(t);
                small++;
            }
        }
        if (big > n/2 || small > n/2) cnt ++;
    }
    cout << cnt;
}
/*
1. 구슬 찾기.
    - 자기 자신보다 무게가 크거나 작은 구슬이 (N-1)/2 보다 많으면 절대로 중간이 될 수 없음.
    - 그러면 쌍 x,y를 받을 때 x <- y 를 저장하는 큰 것의 개수를 찾는 그래프,
      x -> y를 저장하는 작은 것의 개수를 찾는 그래프를 만들어서 둘 다 bfs를 돌려서 개수를 찾으면 됨.

*/
