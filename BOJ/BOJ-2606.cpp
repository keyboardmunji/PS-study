// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
using namespace std;

int n,t,ans = 0;
bool arr[101][101];
bool vis[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> n;
    for (int i =0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    queue <int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int c =q.front(); q.pop();
        for (int i = 1;i<=t;i++) {
            if (arr[c][i] == true && vis[i] == false) {
                vis[i] = true;
                q.push(i);
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}

/*
 1. 그래프 구현
 2. 1번 부터 bfs 한 후 bfs를 거친 수 구하기.
*/