// Authored by : keyboardmunji
// Created on 2025-07-25.
#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,c,S = 1;
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

    cin >> n >> m;
    while (S < n)
        S *= 2;
    seg.resize(S * 2,0);
    while (m--) {
        cin >> a >> b >> c;
        if (a)
            update(b,c);
        else {
            if (b > c)
                swap(b,c);
            cout << sum(b,c,1,1,S) <<'\n';
        }
    }
}
/*
1. 수들의 합 7
    - 전형적인 segment Tree 문제.
*/