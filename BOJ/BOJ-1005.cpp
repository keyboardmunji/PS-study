// Authored by : keyboardmunji,
// Created on 2025-06-13.
#include <bits/stdc++.h>

using namespace std;
int n,x,y,t,k,w;
int tim[1001];
int res[1001];
int indegree[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        fill(res,res+1001,0);
        fill(indegree,indegree+1001,0);
        vector<vector<int>> v(n+1) ;
        for (int i = 1;i<=n;i++)
            cin >> tim[i];
        for (int i = 0; i<k;i++) {
            cin >> x >> y;
            v[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;
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
            if (x == w)
                break;
            for (auto c : v[x]) {
                res[c] = max(res[c],tim[x] + tim[c]);
                if (--indegree[c] == 0) q.push(c);
            }
        }
        cout << tim[w] <<'\n';
    }
}
/*
1. ACM Craft
    - 작업이랑 동일함.
*/
