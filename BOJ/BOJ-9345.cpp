// Authored by : keyboardmunji
// Created on 2025-07-26.
#include <bits/stdc++.h>
using namespace std;

int t,n,k,x,q,a,b,S;
vector<int> maxSeg;
vector<int> minSeg;

void update1(int i, int val) {
    int idx = S + i;
    maxSeg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        maxSeg[idx] = max(maxSeg[idx * 2],maxSeg[idx * 2 + 1]);
    }
}
void update2(int i, int val) {
    int idx = S + i;
    minSeg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        minSeg[idx] = min(minSeg[idx * 2],minSeg[idx * 2 + 1]);
    }
}

int mx(int L, int R, int nodeNum, int nodeL, int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R  >= nodeR) return maxSeg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return max(mx(L,R,nodeNum*2,nodeL,mid),mx(L,R,nodeNum*2+1,mid+1,nodeR));
}
int mn(int L, int R, int nodeNum, int nodeL, int nodeR) {
    if (L > nodeR || R < nodeL) return n;
    if (L <= nodeL && R  >= nodeR) return minSeg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return min(mn(L,R,nodeNum*2,nodeL,mid),mn(L,R,nodeNum*2+1,mid+1,nodeR));
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >>t;
    while (t--) {
        cin >> n >> k;
        S = 1;
        while (S < n)
            S *= 2;
        maxSeg.resize(S * 2);
        fill(maxSeg.begin(), maxSeg.end(), 0);
        minSeg.resize(S * 2);
        fill(minSeg.begin(), minSeg.end(), n);
        for (int i = 0; i < n; i++)
            maxSeg[S+i] = minSeg[S+i] = i;

        for (int i = S - 1; i > 0; i--) {
            maxSeg[i] = max(maxSeg[i * 2],maxSeg[i*2 + 1]);
            minSeg[i] = min(minSeg[i*2],minSeg[i*2 + 1]);
        }
        while (k--) {
            cin >> q >> a >> b;
            if (q) {
                if (mn(a,b,1,0,S - 1) == a && mx(a,b,1,0,S - 1) == b)
                    cout << "YES" << '\n';
                else
                    cout << "NO" <<'\n';
            }else {
                int a1 = maxSeg[S + a], b1 = maxSeg[S + b];
                update1(a,b1);
                update2(a,b1);
                update1(b,a1);
                update2(b,a1);
            }
        }
    }



}
/*
1. 디지털 비디오 디스크
    - 4~6번이 4~6에 존재하는지 확인하기 위해서는 1. min :4 , max : 6 2. n = 3이여야 한다.
    - 여기서 segment tree를 사용하면 ,최대 최소 segment tree만 만들면 조건에 만족하는지 확인할 수 있다.
*/