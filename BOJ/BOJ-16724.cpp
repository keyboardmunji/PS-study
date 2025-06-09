// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
using namespace std;

int n, m,cnt;
string maap[1001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> vis(n,vector<int>(m,0));
    stack<pair<int,int>> v;
    for (int i =0;i<n;i++)
        cin >> maap[i];
    for (int i = 0;i < n;i++) {
        for (int j =0; j<m;j++) {
            if (vis[i][j] == -1) continue;
            int x = i, y = j;
            int chk = 0;
            while (1) {
                vis[x][y] = 1;
                v.push({x,y});
                if (maap[x][y] == 'U') x--;
                else if (maap[x][y] == 'D') x++;
                else if (maap[x][y] == 'L') y--;
                else y++;
                if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1) {
                    chk = 1;
                    break;
                }
                if (vis[x][y] == -1)
                    break;
            }
            if (chk) cnt++;
            while (!v.empty()) {
                vis[v.top().first][v.top().second] = -1;
                v.pop();
            }
        }
    }
    cout << cnt;
}
/*
1. 피리부는 사나이
    - vis 배열을 두고, 0으로 초기화 방문하면 1로 만듬.
    - 가다가 vis를 만나면 이떄까지 방문한 모든 vis를 -1로 만듬. 그다음 cnt + 1
    - 만약 가다가 -1을 만나면 값을 추가하지않음.
    - 만약 가다가 1을 만나면 값을 추가하고  cnt를 증가시킴.
    - 맵 밖으로 나가도 cnt를 증가시켜야함.
    - 시간복잡도는 O(NM)
*/
