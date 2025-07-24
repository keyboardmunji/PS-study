// Authored by : keyboardmunji
// Created on 2025-07-24.
#include <bits/stdc++.h>
using namespace std;

const long long M = 1000000007;
int n,m,k,s = 1,a,b,c;
vector<long long> seg;

long long mul(int L,int R,int nodeNum,int nodeL,int nodeR) {
    if (L > nodeR || R < nodeL) return 1;
    if (L <= nodeL && R >= nodeR) return seg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return mul(L,R,nodeNum*2,nodeL,mid) * mul(L,R,nodeNum * 2 + 1,mid + 1,nodeR) % M;
}

void update(int i, int val) {
    int idx = s + i - 1;
    seg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = seg[idx * 2] * seg[idx * 2 + 1] % M;
    }
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    while (s < n)
        s *= 2;
    seg.resize(s*2,1);
    for (int i = 0; i< n; i++)
        cin >> seg[s + i];
    for (int i = s - 1; i > 0; i--)
        seg[i] = seg[i*2] * seg[i*2 + 1] % M;
    int t = m + k;
    while (t--) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c);
        }else {
            cout << mul(b,c,1,1,s) << '\n';
        }
    }
}
/*
1. 구간 곱 구하기.
    - 수변경이 많이 일어남. + 구간 곱 -> segTree가 좋을듯.
    - 대략 O((M+K)log N)임.
    - 100만 5천이 대략 s최댓값임.
*/