// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for (int i =0; i<m;i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int mn = 10000,idx = 0;
    for (int i = 1; i<= n;i++) {
        queue<int> q;
        vector<int> dist(n+1,-1);
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto t : v[c]) {
                if (dist[t] != -1) continue;
                dist[t] = dist[c] + 1;
                q.push(t);
            }
        }
        int sum = 0;
        for (int j = 1; j<= n;j++) {
            if (i == j) continue;
            sum += dist[j];
        }
        if (mn > sum) {
            mn = sum;
            idx = i;
        }
    }
    cout << idx;
}
/*
1. 케빈 베이컨의 6단계 법칙
    - 회장 뽑기랑 동일한 문제인듯.
    - BFS로 한 정점에서 다른 정점까지의 최댓값을 의미하는 듯.
    - 문제 조건에서 몇 사람을 통하면 모두가 알 수 있다 했고 서로 아니 양방향에 또다른 그래프는 존재하지 않는듯.
*/
