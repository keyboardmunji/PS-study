// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,ex;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<int> indegree(n+1);
    vector<int> result;
    for (int i =0;i <m;i++) {
        cin >> x;
        ex = 0;
        for (int  j= 0; j<x;j++) {
            cin >> y;
            if (j != 0) {
                v[ex].push_back(y);
                indegree[y]++;
            }
            ex = y;
        }
    }
    queue<int> q;
    for (int i = 1; i<=n;i++) {
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int c = q.front(); q.pop();
        result.push_back(c);
        for (auto t : v[c]) {
            if (--indegree[t] == 0) q.push(t);
        }
    }
    bool ch = true;
    for (int i = 1;i<=n;i++)
        if (indegree[i] != 0 ) ch = false;
    if (ch) {
        for (auto c: result) cout << c <<'\n';
    }else
        cout << 0;
}
/*
1. 음악 프로그램
    - 각 pd마다 정한 순서를 그래프로 간선을 그린다. 1 -> 4 ->  3 이런식으로
    - 그 다음 위상정렬을 진행한다.
    - if) 사이클이 있다면, q는 빠져나오지만, indgree의 값이 남아 있을 것이다.
    - 그때는 0을 출력한다.
*/
