// Authored by : keyboardmunji,
// Created on 2025-06-12.
#include <bits/stdc++.h>

using namespace std;
int n,x,y,z;
vector <int> v[10001];
int tim[10001];
int res[10001];
int indegree[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n;i++) {
        cin >> x >> y;
        tim[i] = x;
        if (y == 0) continue;
        for (int j = 0; j<y;j++) {
            cin >> z;
            v[z].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1;i<=n;i++) {
        if (indegree[i] == 0) {
            q.push(i);
            res[i] = tim[i];
        }
    }
    while (!q.empty()) {
        x = q.front(); q.pop();
        tim[x] = res[x];
        for (auto c : v[x]) {
            res[c] = max(res[c], tim[x] + tim[c]);
            if (--indegree[c] == 0) q.push(c);
        }
    }
    cout << *max_element(res + 1, res+n + 1);
}
/*
1. 작업
    - 노드 위상 정렬한 후
    - dp처럼 자식 노드에 자신의 노드를 더한 값의 최댓값을 구하면 되는거 아님?
*/
