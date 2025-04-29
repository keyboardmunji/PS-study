// Authored by : keyboardmunji
// Created on 2025-04-29.
#include <bits/stdc++.h>
using namespace std;

int n,q,cnt;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> v(n+1);
    vector<int> node(n+1,0);
    for (int i = 0;i<n - 1;i++) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int q;
    cin >> q;
    for (int i =0;i<q;i++) {
        int qr;
        cin >> qr;
        if (qr == 1) {
            int a,b;
            cin >> a >> b;
            vector<int> vis(n+1,0);
            vector<int> vis2(n+1,-1); // node 저장용
            vis[a] = 1;
            queue<int> q1;
            q1.push(a);
            while (vis[b] == 0) {
                int c = q1.front(); q1.pop();
                int len = v[c].size();
                for (int j =0;j<len;j++) {
                    if (vis[v[c][j]]) continue;
                    vis2[v[c][j]] = c;
                    vis[v[c][j]] = vis[c] + 1;
                    q1.push(v[c][j]);
                }
            }
            int ex = b;
            cnt += vis[b] - 1;
            while (ex != a) {
                node[ex] += cnt--;
                ex = vis2[ex];
            }
        }else {
            int a;
            cin >> a;
            cout << node[a] <<'\n';
        }
    }
    return 0;
}
/*
1. 매번 bfs -> O(1000^2) => ssap ga nng
*/