// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,k,m,x;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> m;
    vector<vector<int>> v(n+1+m);
    for (int i =1;i<=m;i++) {
        for (int j =0;j<k;j++) {
            cin >> x;
            v[n+i].push_back(x);
            v[x].push_back(n+i);
        }
    }
    vector<int> vis(n+m+ 1,-1);
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (vis[n] == -1) {
        if (q.empty()) {
            cout << -1 ;
            return 0;
        }
        int c = q.front(); q.pop();
        for (auto t : v[c]) {
            if (vis[t] != -1) continue;
            q.push(t);
            vis[t] = vis[c] + 1;
        }
    }
    cout << vis[n] / 2 + 1;
}
/*
1. 환승
    - 흠. 간선 연결하는걸 조합으로 해야하는데 TLE걸릴 것같은데, 배열로 만들면 메모리 초과 날 것 같고~
    - 각 하이퍼 튜브를 하나의 노드라고 생각하면 편한듯. 약간 거쳐가야하는 느낌.
    - 대신 진짜 하이퍼 튜브 역은 없어서 2로 나눈뒤 1을 더해줘야함.
*/
