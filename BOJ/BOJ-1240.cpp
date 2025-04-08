// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<pair<int,int>>> v(n + 1);
    vector <bool> vis(n+1,0);
    for (int i = 0;i<n - 1;i++) {
        int x,y,l;
        cin >> x >> y >> l;
        v[x].push_back({y,l});
        v[y].push_back({x,l});
    }
    for (int i =0;i<m;i++) {
        int x, y;
        for (int j =0;j<=n;j++) vis[j] = 0;
        queue <pair<int,int>> q;
        cin >> x>> y;
        q.push({x,0});
        vis[x] = 1;
        while (q.front().X != y) {
            auto c = q.front(); q.pop();
            int len = v[c.X].size();
            for (int j =0 ;j<len;j++) {
                if (vis[v[c.X][j].X]) continue;
                vis[v[c.X][j].X] = 1;
                q.push({v[c.X][j].X,c.Y + v[c.X][j].Y});
            }
        }
        cout << q.front().Y <<'\n';
    }
    return 0;
}

/*
 1. 트리 입력받기.
 2. bfs로 처리해도 m,n이 모두 1000이하라 시간복잡도가 O(NM)임.
 3. 가능!
*/