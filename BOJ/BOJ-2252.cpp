// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
using namespace std;

int n, m,x,y;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> indegree(n + 1);
    vector<vector<int>> v(n+1);
    for (int i =0 ;i<m;i++) {
        cin >> x >> y;
        v[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for (int i = 1; i<=n;i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int c = q.front(); q.pop();
        cout << c <<' ';
        for (auto t : v[c]) {
            if (--indegree[t] == 0) q.push(t);
        }
    }
}

/*
1. 줄 세우기
    - 위상정렬로 정렬할 예정.
*/
