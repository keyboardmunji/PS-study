// Authored by : keyboardmunji
// Created on 2025-07-27.
#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,S =1;
const int MX = 1000000;
vector<int> seg;

int sum(int L, int R, int nodeNum, int nodeL,int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R >= nodeR) return seg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L,R,nodeNum * 2,nodeL,mid) + sum(L,R,nodeNum * 2 + 1,mid + 1, nodeR);
}

void update(int i, int val) {
    int idx = S + i - 1;
    seg[idx] += val;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }
}

int find(int val) {
    int st = 1, ed = MX,re = MX;
    while (st < ed) {
        int mid = (st + ed) / 2;
        int s = sum(1,mid, 1, 1, S);
        if (s < val)
            st = mid + 1;
        else {
            ed = mid;
            re = min(re, mid);
        }
    }
    return re;
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (S < MX)
        S *= 2;
    seg.resize(S * 2);
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            int x = find(b);
            cout << x << '\n';
            update(x,-1);
        }else {
            cin >> b >> c;
            update(b,c);
        }
    }
}
/*
1. 사탕상자.
    - parametric search로 순위를 찾는 함수릃 하나 설정함.
    - segment tree로는 구간내에서 만족하는지 안하는지를 찾으면 될듯.
*/