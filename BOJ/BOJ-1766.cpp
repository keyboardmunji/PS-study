// Authored by : keyboardmunji,
// Created on 2025-06-11.
#include <bits/stdc++.h>

using namespace std;
int n,m,a,b;
vector<int> v[32001];
int indegree[32001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0;i<m;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 1; i<=n;i++)
        if (indegree[i] == 0) pq.push(i);
    while (!pq.empty()) {
        int c = pq.top(); pq.pop();
        cout << c<<' ';
        for (auto t: v[c])
            if (--indegree[t] == 0) pq.push(t);
    }

}
/*
1. 문제집
    - 노드 개수와 간선의 정보를 받고
    - 위상정렬 해준다.
*/
