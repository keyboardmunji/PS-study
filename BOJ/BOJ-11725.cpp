// Authored by : keyboardmunji
// Created on 2025-04-08.
#include <bits/stdc++.h>
using namespace std;

int n;
int vis[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> m(n + 1);
    for (int i =0;i<n - 1;i++) {
        int x,y;
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int c= q.front();q.pop();
        int len = m[c].size();
        for (int i = 0;i<len;i++) {
            if (vis[m[c][i]]) continue;
            vis[m[c][i]] = c;
            q.push(m[c][i]);
        }
    }
    for (int i =2;i<=n;i++)
        cout << vis[i] <<'\n';
    return 0;
}

/*
 *벡터 안쓰면 어떻게 풀지..? STL은 위대하다!!!
 1.벡터에 연결된 점들을 다 담는다.
 2. queue에 1을 집어넣는다.
 3. 1과 연결된 점들은 다 자식이므로 부모가 1임.
 4. 그렇게 bfs를 돌리면 된다.
*/