// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int m[4][4];
bool vis[4][4];
int dx[2] = {0,1};
int dy[2] = {1,0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i= 1; i<=n;i++)
        for (int j =1;j<=n;j++)
            cin >> m[i][j];

    queue<pair<int,int>> q;
    q.push({1,1});
    vis[1][1] = true;
    while (!q.empty()) {
        auto c = q.front(); q.pop();
        if (m[c.X][c.Y] == -1) {
            cout << "HaruHaru";
            return 0;
        }
        for (int i =0;i<2;i++) {
            int x1 = c.X + dx[i]*m[c.X][c.Y];
            int y1 = c.Y + dy[i]*m[c.X][c.Y];
            if (x1 <= 0 || y1 <= 0 || x1 > n || y1 > n || vis[x1][y1]) continue;
            vis[x1][y1] = true;
            q.push({x1,y1});
        }
    }
    cout << "Hing";
    return 0;
}

/*
 1. n*n의 구역이 주어짐.
 2. 쩰리는 칸에 적혀있는 수만큼 오른쪽 이나 아래쪽으로 이동가능함.
 3. 그러면 첫번째 구역부터 bfs를 돌린 다음, 마지막 칸에 vis를 하는지 체크하면 됨.
*/

