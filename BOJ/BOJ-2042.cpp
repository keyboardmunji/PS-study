// Authored by : keyboardmunji
// Created on 2025-07-24.
#include <bits/stdc++.h>
using namespace std;

int n,m,k,si;
long long a,b,c;
vector<long long> v;

long long sum(int L,int R, int nodeNum, int nodeL, int nodeR) {
    if (R < nodeL || L > nodeR) return 0;
    if (L <= nodeL && R >= nodeR) return v[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L,R,nodeNum * 2, nodeL, mid) + sum(L,R,nodeNum*2+1, mid +1 , nodeR);
}
void update(int i, long long val) {
    int idx = i + si - 1;
    v[idx] = val;
    while (idx > 1) {
        idx /= 2;
        v[idx] = v[idx * 2] + v[idx *2 + 1];
    }
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    // size찾기.
    si = 1;
    while (si < n)
        si *= 2;
    v.resize(si * 2, 0);
    for (int i = 0; i< n; i++)
        cin >> v[si + i];
    // 세그 트리 만들기.
    for (int i = si - 1; i >= 0; i--)
        v[i] = v[i*2] + v[i*2 + 1];
    int t = m + k;
    while (t--) {
        cin >> a >> b >> c;
        if (a == 1)
            update(b,c);
        else if (a == 2)
            cout << sum(b,c,1,1,si) << '\n';
    }
}
/*
1. 구간 합 구하기.
    - 세그먼트 트리 연습.
*/