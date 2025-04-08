// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m,cnt;
int mp[101][71];
bool vis[101][71];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {0,1,-1,1,-1,0,1,-1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0;i<n;i++)
        for (int j = 0;j<m;j++)
            cin >> mp[i][j];
    for (int i =0;i<n;i++) {
        for (int j = 0; j<m;j++) {
            if (vis[i][j]) continue;
            queue<pair<int,int>> q;
            bool ch = true;
            vis[i][j] = 1;
            q.push({i,j});
            while (!q.empty()) {
                auto c = q.front(); q.pop();
                for (int k =0;k<8;k++) {
                    int x1 = c.X + dx[k];
                    int y1 = c.Y + dy[k];
                    if (x1 < 0 || y1 <0 || x1 >= n || y1 >= m) continue;
                    if (mp[x1][y1] > mp[c.X][c.Y])
                        ch = false;
                    else if (mp[x1][y1] == mp[c.X][c.Y] && vis[x1][y1] == false) {
                        vis[x1][y1] = true;
                        q.push({x1,y1});
                    }
                }
            }
            if (ch) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}

/*
 1. 산봉우리 개수 세기 : 상하 좌우, 대각선까지 포함해서 모두 작아야함.
 2 예제 입력 1에서 산봉우리는 {0,0} , [{0,7},{1,7}],[{6,2},{6,3},{7,4}] 이렇게 3개임.
 3. 즉 인접하다라는 의미를 잘 이해해야함.
 4. bfs탐색을 진행할 것임.
 5. 자기 자신과 같은 수 가 있접해 있으면 vis를 확인하고 vis가 true이면 무시, 아니면 그 쪽으로 넘어갈 준비.
 6. 자기 자신보다 큰 수가 인접해 있으면 ch = false로 만든 후 자기자신과 같은 수가 인접해 있을 수 있으니 계속 탐색
 7. ch가 false이면 cnt를 증가시키지 않고, ch 가 true이면 증가시킴.
*/

