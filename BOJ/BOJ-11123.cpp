// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int t;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        int h,w,cnt = 0;
        string m[101];
        bool vis[101][101] = {};
        cin >> h >> w;
        for (int i =0 ;i <h;i++) {
            cin >> m[i];
        }
        for (int i =0;i<h;i++) {
            for (int j =0 ;j<w;j++) {
                if (m[i][j] == '.' || vis[i][j]) continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                cnt++;
                while (!q.empty()) {
                    auto c = q.front(); q.pop();
                    for (int k =0;k<4;k++) {
                        int x1 = c.X + dx[k];
                        int y1 = c.Y + dy[k];
                        if (x1 < 0 || y1 < 0 || x1 >= h || y1 >= w || m[x1][y1] == '.' || vis[x1][y1]) continue;
                        vis[x1][y1] = true;
                        q.push({x1,y1});
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
 2. 따라서 시간복잡도는 O(HW)임.
 3. 가능!
*/