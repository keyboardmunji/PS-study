// Authored by : keyboardmunji,
// Created on 2025-06-23.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int MAX = 10001;
int m,n;
string s[101];
vector<pair<int,int>> v[10001];
vector<int> val(10001,MAX);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for (int i =0 ;i<n;i++) cin >> s[i];
    for (int i = 0;i<n;i++) {
        for (int j =0;j<m;j++) {
            for (int k = 0; k<4;k++) {
                int x1 = i + dx[k];
                int y1 = j + dy[k];
                if (x1 < 0 || y1< 0 || x1>=n || y1 >=m) continue;
                v[i*m + j].push_back({s[x1][y1]-'0',x1*m+y1});
            }
        }
    }
    val[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({val[0],0});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (val[cur.Y] != cur.X) continue;
        for (auto t : v[cur.Y]) {
            if (val[t.Y] <= cur.X + t.X) continue;
            val[t.Y] = cur.X + t.X;
            pq.push({val[t.Y],t.Y});
        }
    }
    cout << val[(n-1)*m + m-1];
}
/*
문제 : 알고스팟
    - 2차원 배열을 트리로 변환하면 대략 단방향 간선 4만개 정도가 생김.
    - 여기서 (1,1), (n,m)다익스트라 돌리면 될듯.
*/
