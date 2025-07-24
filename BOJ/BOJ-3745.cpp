// Authored by : keyboardmunji
// Created on 2025-07-25.
#include <bits/stdc++.h>
using namespace std;

int n,x,S = 1;
vector<int> seg;

bool comp(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void update(int i, int val) {
    int idx = S + i;
    seg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = max(seg[idx * 2],seg[idx * 2 + 1]);
    }
}

int mx (int L,int R, int nodeNum, int nodeL, int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R >= nodeR) return seg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return max(mx(L,R,nodeNum * 2,nodeL,mid), mx(L,R,nodeNum * 2 + 1,mid+1,nodeR));
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n) {
        S = 1;
        while (S < n)
            S *= 2;
        seg.resize(S * 2);
        fill(seg.begin(), seg.end(), 0);
        vector<pair<int,int>> p;
        for (int i = 0; i < n; i++){
            cin >> x;
            p.push_back({x,i});
        }
        sort(p.begin(), p.end(),comp);
        int ans = 0;
        for (auto q : p) {
            int m = mx(0,q.second,1,0,S-1);
            update(q.second, m + 1);
            ans = max(ans,m+1);
        }
        cout << ans <<'\n';
    }
}
/*
1. 오름세
    - segment Tree로 LIS 구하기.
*/