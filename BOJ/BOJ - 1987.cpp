// Authored by : keyboardmunji
// Created on 2025-07-23.
#include <bits/stdc++.h>
using namespace std;

int r,c,mx;
string mp[21];
bool vis[26];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int c2i(char q) {
    return q - 'A';
}

void dfs(int i,int j,int cnt) {
    mx = max(mx,cnt);
    for (int k = 0;k<4;k++) {
        int x1 = i + dx[k];
        int y1 = j + dy[k];
        if (x1 < 0 || x1 >= r || y1 < 0 || y1 >= c || vis[c2i(mp[x1][y1])]) continue;
        vis[c2i(mp[x1][y1])] = true;
        dfs(x1,y1,cnt+1);
        vis[c2i(mp[x1][y1])] = false;
    }
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i<r;i++)
        cin >> mp[i];
    vis[c2i(mp[0][0])] = true;
    dfs(0,0,1);
    cout << mx;
}
/*
1. 알파벳
    - dfs로 푸는게 가장 좋을듯.
*/