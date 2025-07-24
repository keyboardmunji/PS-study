// Authored by : keyboardmunji
// Created on 2025-07-25.
#include <bits/stdc++.h>
using namespace std;

int n,q,a,b,c,S = 1;
vector<long long> seg;

void update(int i, int val) {
    int idx = S + i - 1;
    seg[idx] = seg[idx] + val;
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
    seg.resize(S * 2, 0);
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c);
        }else {
            cout << sum(b,c,1,1,S) << '\n';
        }
    }
}
/*
1. 가계부(Hard)
    - segment tree로 구간 합 구하기.
    - 주어진 수입/지출이 없으면 0으로 처리해놓고 하면 됨.
    - 동일한 날짜가 들어왔을 때 더해야하는 것 같음. -> 추가한다라고 적혀있어서
*/