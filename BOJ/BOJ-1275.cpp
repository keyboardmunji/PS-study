// Authored by : keyboardmunji
// Created on 2025-07-25.
#include <bits/stdc++.h>
using namespace std;

int n,q,a,b,x,y,S = 1;
vector<long long> seg;

void update(int i, int val) {
    int idx = S + i - 1;
    seg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }
}

long long sum (int L,int R, int nodeNum, int nodeL, int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R >= nodeR) return seg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L,R,nodeNum * 2,nodeL,mid) + sum(L,R,nodeNum * 2 + 1,mid+1,nodeR);
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    while (S < n)
        S *= 2;
    seg.resize(S * 2);
    for (int i = 0; i< n; i++)
        cin >> seg[S + i];
    for (int i = S - 1; i > 0; i--)
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    while (q--) {
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);
        cout << sum(x,y,1,1, S) <<'\n';
        update(a,b);
    }
}
/*
1. 커피숍2
    - 노골적인 segment tree문제.
*/