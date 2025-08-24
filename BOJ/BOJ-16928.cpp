// Authored by : keyboardmunji
// Created on 2025-08-25.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m,x,y;
pair<int,int> arr[101]; // -1 : 뱀, 0 : x, 1: 사다리
int vis[101];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    fill (vis, vis+101, -1);
    cin >> n >> m;
    for (int i = 0 ; i<n;i++) {
        cin >> x >> y;
        arr[x].X = 1;
        arr[x].Y = y;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x].X = -1;
        arr[x].Y = y;
    }
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (vis[100] == -1) {
        int c = q.front(); q.pop();
        for (int i = 1; i <= 6;i++) {
            int dis = c + i;
            if (dis > 100) continue;
            if (arr[dis].X != 0)
                dis = arr[dis].Y;
            if (vis[dis] != -1) continue;
            vis[dis] = vis[c] + 1;
            q.push(dis);
        }
    }
    cout << vis[100];
}
/*
1. 뱀과 사다리 게임
    - BFS
*/