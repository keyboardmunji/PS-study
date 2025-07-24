// Authored by : keyboardmunji
// Created on 2025-07-24.
#include <bits/stdc++.h>
using namespace std;

int n,m,S = 1,x,a,b;
vector<int> minSeg;
vector<int> maxSeg;

int mx(int L,int R,int nodeNum,int nodeL,int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R >= nodeR) return maxSeg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return max(mx(L,R,nodeNum*2,nodeL,mid),mx(L,R,nodeNum*2+1,mid+1,nodeR));
}
int mn(int L,int R,int nodeNum,int nodeL,int nodeR) {
    if (L > nodeR || R < nodeL) return 1000000001;
    if (L <= nodeL && R >= nodeR) return minSeg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return min(mn(L,R,nodeNum*2,nodeL,mid),mn(L,R,nodeNum*2+1,mid+1,nodeR));
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (S < n)
        S *= 2;
    minSeg.resize(S * 2,1000000001);
    maxSeg.resize(S * 2,0);
    for (int i = 0; i< n;i++) {
        cin >> x;
        minSeg[S + i] = x;
        maxSeg[S + i] = x;
    }
    for (int i = S - 1; i > 0; i--) {
        minSeg[i] = min(minSeg[i * 2],minSeg[i*2+1]);
        maxSeg[i] = max(maxSeg[i*2],maxSeg[i*2+1]);
    }
    while (m--) {
        cin >> a >> b;
        cout << mn(a,b,1,1,S) << ' ' << mx(a,b,1,1,S) << '\n';
    }
}
/*
1. 최솟값과 최댓값
    - 세그트리를 모르던 시절엔 O(NM)이라 시간초과가 나겠지만 이젠 아니야~
    - 지금은 O(MlogN)에 해결가능!
*/