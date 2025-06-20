// Authored by : keyboardmunji,
// Created on 2025-06-20.
#include <bits/stdc++.h>
using namespace std;

int maap[201][201];
int vis[31][201][201];
int w,h,k,idx;
bool ch = false;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int hx[8] = {1,1,2,2,-1,-1,-2,-2};
int hy[8] = {-2,2,1,-1,2,-2,1,-1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> k >> w >> h;
    for (int i =0 ;i< h;i++)
        for (int j = 0; j< w;j++) cin >> maap[i][j];
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    vis[0][0][0] = 1;
    while (!q.empty() && !ch) {
        int a,b,c;
        tie(a,b,c) = q.front(); q.pop();
        for (int i =0; i<4;i++) {
            int x = b + dx[i];
            int y = c + dy[i];
            if (x < 0 || y < 0 || x >= h || y >= w || maap[x][y] == 1 || vis[a][x][y] != 0) continue;
            vis[a][x][y] = vis[a][b][c] + 1;
            q.push({a,x,y});
        }
        for (int i = 0 ; i< 8;i++) {
            int x = b + hx[i];
            int y = c + hy[i];
            if (x < 0 || y < 0 || x >= h || y >= w || a + 1 > k || maap[x][y] == 1 || vis[a + 1][x][y] != 0) continue;
            vis[a+1][x][y] = vis[a][b][c] + 1;
            q.push({a+1,x,y});
        }
        for (int i = 0; i<= k;i++) {
            if (vis[i][h-1][w-1] != 0) {
                ch = true;
                idx = i;
                break;
            }
        }
    }
    if (ch)
        cout << vis[idx][h-1][w-1] - 1;
    else
        cout << -1;
}

/*
1. 말이 되고픈 원숭이
    - BFS로 O(KWH)안에 해결할 수 있음.
    - vis 배열을 k*h*w로 만든 다음 말처럼 이동한 횟수에 따라 vis를 처리하면 될듯.
*/
