// Authored by : keyboardmunji
// Created on 2025-07-25.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,x,y,S = 1;
vector<int> seg[2]; // 0 idx : 처리된 작은 값, 1 idx : 처리된 큰 값
void update(int i,int a) {
    int idx = S + i;
    seg[a][idx] = 1;
    while (idx > 1) {
        idx /= 2;
        seg[a][idx] = seg[a][idx*2] + seg[a][idx*2+1];
    }
}

int sum(int L,int R,int nodeNum, int nodeL, int nodeR,int a) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL && R >= nodeR) return seg[a][nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L,R,nodeNum*2,nodeL,mid,a) + sum(L,R,nodeNum*2+1,mid+1,nodeR,a);
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (S < n)
        S *= 2;
    seg[0].resize(S*2, 0);
    seg[1].resize(S*2, 0);
    vector<pair<int,int>> p;
    for (int i =0; i<n;i++) {
        cin >> x;
        p.push_back({x,i});
    }
    int cnt = 0, t = 0;
    bool chk = true;
    sort(p.begin(), p.end());
    while (t < n) {
        if (chk) {
            x = sum(0,p[cnt].Y,1,0,S-1,1);
            y = sum (0,p[cnt].Y,1,0,S-1,0);
            cout << p[cnt].Y - y - x <<'\n';
            update(p[cnt].Y,0);
        }else {
            x = sum(p[n - cnt - 1].Y, n - 1,1,0,S-1,0);
            y = sum(p[n - cnt - 1].Y, n - 1,1,0,S-1,1);
            cout << n - 1 - p[n - cnt - 1].Y  - y - x << '\n';
            update(p[n-cnt-1].Y, 1);
            cnt++;
        }
        t++;
        chk = !chk;
    }
    for (auto c : p) {

    }
}
/*
1. 터보소트
    - 그냥 돌리면 O(N^2)임.
    - 고민한 결과, 자기 앞에 이미 처리된 수들만 파악하면 된다는 것을 알게됨. -> 이를 세그먼트 트리로 저장하면 될듯.
*/