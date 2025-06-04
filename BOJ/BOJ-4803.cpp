// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int m,n,x,y;
vector<vector<int>> v;
vector<bool> vis;
int dfs(int node, int pr) {
    if (vis[node] == true) return -1;
    vis[node] = true;
    for (auto i : v[node]) {
        if (i == pr) continue;
        if (dfs(i,node) == -1)
            return - 1;
    }
    return 1;
}
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    while (++t) {
        if (t != 1) cout << '\n';
        cin >> n >> m;
        bool ch = false;
        if (n == 0 && m == 0) return 0;
        v.clear();
        v.resize(n+1);
        vis.clear();
        vis.resize(n+1,false);
        for (int i =0 ;i< m;i++) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int cnt = 0;
        cout << "Case " << t <<": ";
        for (int i = 1;i<=n;i++) {
            if (vis[i] == true) continue;
            if (dfs(i,0) != -1) {
                cnt += 1;
            }
        }
        if (cnt == 0)
            cout << "No trees.";
        else if (cnt == 1)
            cout << "There is one tree.";
        else
            cout << "A forest of " << cnt << " trees.";
    }
}
/*
1. 트리
    - 예시를 보자.
    - T1 : 1~4, 5, 6 이렇게 3개이다.
    - 그럼 없는 경우는 언제 일까? -> 순회를 하면 없는게 된다.
    - 그럼 vis랑, dfs를 활용해서 트리 개수를 구하면 될듯. ->  bfs해도 되는데, dfs연습좀.
*/
