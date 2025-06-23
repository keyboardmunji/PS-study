// Authored by : keyboardmunji,
// Created on 2025-06-23.
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int MAX = 400000001;
int n,e,a,b,c,v1,v2;
vector<pair<int,int>> v[801];

int func1(int st, int ed) {
    vector<int> val(n+1,MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    val[st] = 0;
    pq.push({val[st],st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != val[cur.Y]) continue;
        for (auto c : v[cur.Y]) {
            if (val[c.Y] <= cur.X + c.X) continue;
            val[c.Y] = cur.X + c.X;
            pq.push({val[c.Y],c.Y});
        }
    }
    if (val[ed] == MAX) return -1;
    return val[ed];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;
    for (int i = 0; i< e;i++) {
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    cin >> v1 >> v2;
    int ans1 = MAX,ans2 = MAX;
    if (func1(1,v1) != -1 && func1(v1,v2) != -1 && func1(v2,n) != -1)
        ans1 = func1(1,v1) + func1(v1,v2) + func1(v2,n);
    if (func1(1,v2) != -1 && func1(v2,v1) != -1 && func1(v1,n) != -1)
        ans2 = func1(1,v2) + func1(v2,v1) + func1(v1,n);
    if (ans1 == MAX && ans2 == MAX)
        cout << -1;
    else
        cout << min(ans1,ans2);
}
/*
문제 : 특정한 최단 경로
    - 우선 최대 3번의 다익스트라를 돌려야함.
    - n = 1,v1,v2일때 다 돌린후. n = 1 -> v1 - > v2 -> n 이랑, 1 -> v2 -> v1 -> n이랑 비교해야할듯.
    - v1 = 1 or v2 = N일때 주의하기.
*/
