// Authored by : keyboardmunji,
// Created on 2025-06-22.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int MAX = 0x7FFFFFFF;
int n,m,a,b,c,st,ed;
vector<pair<int,int>> v[1001];
vector<int> val(1001,MAX);
vector<int> pre(1001,0);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0 ;i <m ;i++) {
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    cin >> st >> ed;
    val[st] = 0;
    pre[st] = st;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({val[st],st});

    while (!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if (val[c.Y] != c.X) continue;
        for (auto t : v[c.Y]) {
            if (val[t.Y] <= t.X + c.X) continue;
            val[t.Y] = t.X + c.X;
            pre[t.Y] = c.Y;
            pq.push({val[t.Y],t.Y});
        }
    }
    vector<int> ans;
    int x = ed;
    while (x != st) {
        ans.push_back(x);
        x = pre[x];
    }
    ans.push_back(st);
    reverse(ans.begin(),ans.end());
    cout << val[ed] <<'\n' << ans.size() <<'\n';
    for (auto t: ans) cout << t <<' ';
}

/*
1. 최소비용 구하기 2
    - 다익스트라로 최소비용 구한 후 경로복원하는 문제.
*/
