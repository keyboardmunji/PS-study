// Authored by : keyboardmunji
// Created on 2025-07-24.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,s = 1;
vector<int> seg;
vector<pair<int,int>> arr;

bool comp(pair<int,int> a,pair<int,int> b) {
    if (a.X == b.X)
        return a.Y > b.Y;
    return a.X < b.X;
}

int findMax(int L,int R, int nodeNum, int nodeL, int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && nodeR <= R) return seg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return max(findMax(L,R,nodeNum*2,nodeL,mid),findMax(L,R,nodeNum*2+1,mid+1,nodeR));
}

void update(int i, int val) {
    int idx = s + i;
    seg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = max(seg[idx*2], seg[idx*2+1]);
    }
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (s < n)
        s *= 2;
    seg.resize(s * 2, 0);
    for (int i = 0; i< n;i++) {
        int x;
        cin >> x;
        arr.push_back({x,i});
    }
    sort(arr.begin(), arr.end(),comp);
    int ans = 0;
    for (auto c : arr) {
        int mx = findMax(0,c.Y,1,0, s - 1);
        update(c.Y,mx+1);
        ans = max(ans,mx + 1);
    }
    cout << ans;
}
/*
1. 가장 긴 부분수열
    - segtree를 활용한 가장 긴 부분수열 해결하기.
    - 대략 O(NlogN)에 구할 수 있음.
    - 같은 값들을 어떻게 처리할지가 제일 고민인데, 큰 인덱스 부터 처리하면 될듯.
*/