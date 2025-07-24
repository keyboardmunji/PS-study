// Authored by : keyboardmunji
// Created on 2025-07-25.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 199999;
int M = 1000000007;
int n,S = 1;
long long x;
long long mul = 1;
vector<long long> sumSeg;
vector<int> cntSeg;

void cntUpdate(int i) {
    int idx = S + i;
    cntSeg[idx]++;
    while (idx > 1) {
        idx /= 2;
        cntSeg[idx] = cntSeg[idx * 2] + cntSeg[idx * 2 + 1];
    }
}

int cnt1(int L,int R,int nodeNum,int nodeL,int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R >= nodeR) return cntSeg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return cnt1(L,R,nodeNum*2,nodeL,mid) + cnt1(L,R,nodeNum*2+1,mid+1,nodeR);
}

void sumUpdate(int i) {
    int idx = S + i;
    sumSeg[idx] = sumSeg[idx] + i;
    while (idx > 1) {
        idx /= 2;
        sumSeg[idx] = sumSeg[idx * 2] + sumSeg[idx * 2 + 1];
    }
}

long long sum1(int L,int R,int nodeNum,int nodeL,int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R >= nodeR) return sumSeg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum1(L,R,nodeNum*2,nodeL,mid) + sum1(L,R,nodeNum*2+1,mid+1,nodeR);
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (S < MAX)
        S *= 2;
    sumSeg.resize(S * 2);
    cntSeg.resize(S * 2);
    for (int i = 0; i< n;i++) {
        cin >> x;
        long long sum = cnt1(0,x-1,1,0,S-1) * x - sum1(0,x-1,1,0,S-1) + sum1(x+1,MAX,1,0,S-1) -cnt1(x + 1,MAX,1,0,S-1) * x;
        sum %= M;
        if (i != 0)
            mul = mul * sum % M;
        cntUpdate(x);
        sumUpdate(x);
    }
    cout << mul << '\n';
}
/*
1. 나무심기
    - 결국 자기 오른쪽과 왼쪽의 나무 갯수를 알아야함. -> 이를 segment tree로 구할 수 있음.
*/