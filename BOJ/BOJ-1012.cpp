// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m,t,k;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        bool mp[51][51] = {};
        bool vis[51][51] ={};
        int cnt =0;
        cin >> m >> n >> k;
        for (int i =0 ;i <k;i++) {
            int x,y;
            cin >> x >> y;
            mp[y][x] = true;
        }
        for (int i =0;i<n;i++) {
            for (int j =0;j<m;j++) {
                if (vis[i][j] || mp[i][j] == false) continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = true;
                cnt++;
                while (!q.empty()) {
                    auto c = q.front(); q.pop();
                    for (int h= 0;h<4;h++) {
                        int x1 = c.X + dx[h];
                        int y1 = c.Y + dy[h];

                        if (x1 < 0 || y1 < 0 || x1 > n || y1 > m || !mp[x1][y1] || vis[x1][y1]) continue;
                        q.push({x1,y1});
                        vis[x1][y1] = true;
                    }
                }
            }
        }
        cout << cnt <<'\n';
    }
    return 0;
}

/*
 1. bfs를 최대 몇번해야하는지 질문하는 문제임.
 2. 따라서 시간복잡도는 o(NM)임.
 3. 가능!
*/