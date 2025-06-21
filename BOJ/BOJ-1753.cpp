// Authored by : keyboardmunji,
// Created on 2025-06-20.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int MAX = 0x0f0f0f0f;
int v,e,st,x,y,w;
vector<pair<int,int>> q[20001];
vector<int> val(20001,MAX);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e >> st;
    for (int i =0 ;i < e;i++) {
        cin >> x >> y >> w;
        q[x].push_back({w,y});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    val[st] = 0;
    for (auto c: q[st])
        pq.push(c);
    while (!pq.empty()){
        auto c = pq.top(); pq.pop();
        if (val[c.Y] <= c.X) continue;
        val[c.Y] = c.X;
        for (auto t : q[c.Y])
            pq.push({val[c.Y] + t.X,t.Y});
    }
    for (int i = 1;i<=v;i++) {
        if (val[i] == MAX)
            cout << "INF";
        else
            cout << val[i];
        cout <<'\n';
    }

}

/*
1. 최단 경로
    - 다익스트라 알고리즘 연습하기
*/
