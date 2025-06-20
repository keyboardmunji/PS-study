// Authored by : keyboardmunji,
// Created on 2025-06-20.
#include <bits/stdc++.h>
using namespace std;

string maap[1001];
int vis[11][1001][1001];
int n,m,k,idx;
bool ch = false;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i<n;i++) cin >> maap[i];
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    vis[0][0][0] = 1;
    while (!q.empty() && !ch) {
        int a,b,c;
        tie(a,b,c) = q.front(); q.pop();
        for (int i = 0;i < 4; i++) {
            int x = b + dx[i];
            int y = c + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (maap[x][y] == '1' && a + 1 <= k && vis[a + 1][x][y] == 0) {
                vis[a+1][x][y] = vis[a][b][c] + 1;
                q.push({a+1,x,y});
            }else if (maap[x][y] == '0' && vis[a][x][y] == 0){
                vis[a][x][y] = vis[a][b][c] + 1;
                q.push({a,x,y});
            }
        }
        for (int i = 0;i <= k;i++) {
            if (vis[i][n-1][m-1] != 0) {
                idx = i;
                ch = true;
                break;
            }
        }
    }
    if (ch)
        cout << vis[idx][n-1][m-1];
    else
        cout << -1;
}

/*
1. 문 부수고 이동하기 2
    - 이건 O(NMK)임. BFS로 가능.
*/
