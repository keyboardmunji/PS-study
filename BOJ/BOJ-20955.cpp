// Authored by : keyboardmunji,
// Created on 2025-06-12.
#include <bits/stdc++.h>

using namespace std;
int n,m,u,v,cnt;
vector<int> a[100001];
int vis[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0 ;i <m;i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1;i<=n;i++) {
        if (vis[i] != 0) continue;
        cnt++;
        int ccnt = 0;
        queue<int> q;
        q.push(i);
        vis[i] = i;
        while (!q.empty()) {
            int c =q.front(); q.pop();
            for (auto t : a[c]) {
                if (vis[t] != 0) {
                    if (t != vis[c]) {
                        ccnt++;
                    }
                    continue;
                }
                q.push(t);
                vis[t] = c;
            }
        }
        cnt += ccnt / 2;
    }
    cout << cnt - 1;
}
/*
1. 민서의 응급수술
    - 트리는 사이클만 없고, 모든 노드들이 연결 되어있으면 됨.
    - 그러면 모든 노드들이 연결되기 위해서는 bfs를 몇번 돌리는지 확인하면 됨. 돌리는 횟수 - 1이 연결해야하는 횟수임.
    - 사이클은 어떻게 없앨 수 있을까? -> bfs를 돌면서 만약 vis한 곳을 탐색하려고 하면 탐색하지 않고 cnt++를 하면 될듯.
*/
