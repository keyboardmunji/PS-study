// Authored by : keyboardmunji
// Created on 2025-07-03.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const long long MAX = 100000000000001;
long long n,m,a,b,c,x,y,z,mx,st,ed;
vector<pair<long long,int>> v[100001];
vector<long long> val(100001,MAX);
vector<int> w;

bool ps(long long l){
    priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    fill(val.begin(),val.end(),MAX);

    val[a] = 0;
    pq.push({0,a});
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        if(val[t.Y] != t.X) continue;
        for(auto p :v[t.Y]){
            if(p.X > l || p.X + t.X >= val[p.Y]) continue;
            val[p.Y] = p.X + t.X;
            pq.push({val[p.Y], p.Y});
        }
    }
    if(val[b] > c) return 0;
    return 1;
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> a >> b >> c;
    for(int i =0; i<m;i++){
        cin >> x >> y >> z;
        v[x].push_back({z,y});
        v[y].push_back({z,x});
        ed = max(ed,z);
    }

    while(st < ed){
        long long mid = (st + ed) / 2;
        if(ps(mid)) ed = mid;
        else st = mid + 1;
    }

    if(ps(st)) cout << st;
    else cout << -1;
    return 0;
}
/*
1. 골목 대장 호석 - 효율성 2
    - 두가지 조건을 만족해야함.
        1. 주어진 돈으로 a -> b로 갈 수 있어야한다.
        2. 다음, 골목에서 지나는 경로의 비용이 가장 작아야한다.
    - 경로의 비용을 기준으로 다익스트라를 진행하면 될듯.
*/