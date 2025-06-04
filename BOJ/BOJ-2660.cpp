// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n,x,y;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> v(n+1);
    vector<int> ans(n+1);
    while (1) {
        cin >> x >> y;
        if (x == -1 && y == -1)
            break;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int mn = 51,cnt = 0;
    for (int i = 1;i<=n;i++) {
        queue<int> q;
        vector<int> dist(n+1,-1);
        q.push(i);
        dist[i] = 0;
        int mnn = 0;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto t : v[c]) {
                if (dist[t] != -1) continue;
                q.push(t);
                dist[t] = dist[c] + 1;
                mnn = dist[t];
            }
        }
        if (mn > mnn) {
            mn = mnn;
            cnt = 0;
            ans[cnt++] = i;
        }else if (mn == mnn) {
            ans[cnt++] = i;
        }
    }
    cout << mn <<' ' << cnt <<'\n';
    sort(ans.begin(), ans.begin() + cnt);
    for (int i = 0 ;i< cnt;i++)
        cout << ans[i] <<' ';
}
/*
1. 회장 뽑기
    - BFS로 한 정점에서 다른 정점까지의 최댓값을 의미하는 듯.
    - 문제 조건에서 몇 사람을 통하면 모두가 알 수 있다 했고 서로 아니 양방향에 또다른 그래프는 존재하지 않는듯.
*/
