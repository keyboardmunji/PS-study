// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
int ans[10001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for (int i =0 ;i< m;i++) {
        cin >> x>> y;
        v[y].push_back(x);
    }
    int mx = 0,s = 0;
    for (int i =1; i<=n;i++) {
        queue<int> q;
        vector<bool> vis(n+1);
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int c= q.front(); q.pop();
            for (auto t : v[c]) {
                if (vis[t] == true) continue;
                q.push(t);
                vis[t] = true;
            }
        }
        int cnt = 0;
        for (int i = 1;i<=n;i++) {
            if (vis[i] == true) cnt++;
        }
        if (cnt > mx) {
            s = 0;
            mx = cnt;
            ans[s++] = i;
        }else if (cnt == mx)
            ans[s++] = i;
    }
    for (int i =0; i< s;i++)
        cout << ans[i] <<' ';
}
/*
1. 효율적인 해킹
    - 단방향 그래프로 가장 많은 노드와 연결된 걸 찾으면 되는듯.
*/
