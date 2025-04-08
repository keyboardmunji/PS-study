// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m,mx,cnt;
int mp[501][501];
bool vis[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i= 0;i<n;i++)
        for (int j =0;j<m;j++)
            cin >> mp[i][j];

    for (int i= 0;i<n;i++) {
        for (int j =0;j<m;j++) {
            if (vis[i][j] || !mp[i][j]) continue;
            queue<pair<int,int>> q;
            int cnt2 = 0;
            q.push({i,j});
            vis[i][j] = 1;
            cnt++;
            while (!q.empty()) {
                auto c = q.front(); q.pop();
                cnt2++;
                for (int k = 0; k <4;k++) {
                    int x1 = c.X + dx[k];
                    int y1 = c.Y + dy[k];
                    if (x1 < 0 || y1 < 0 || x1 >=n || y1 >= m || vis[x1][y1] || !mp[x1][y1]) continue;
                    q.push({x1,y1});
                    vis[x1][y1] = true;

                }
            }
            mx = max(mx,cnt2);
        }
    }

    cout << cnt <<'\n' << mx;

    return 0;
}

/*
 1. bfs의 탐색 길이중 가장 긴 것을 구하기
*/