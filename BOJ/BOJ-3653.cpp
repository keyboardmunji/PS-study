// Authored by : keyboardmunji
// Created on 2025-07-25.
#include <bits/stdc++.h>
using namespace std;

int x,t,n,m,S;
vector<int> seg;
vector<int> id;

void update(int i, int val) {
    int idx = S + i - 1;
    seg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = seg[idx*2] + seg[idx*2+1];
    }
}

int sum(int L,int R,int nodeNum, int nodeL, int nodeR) {
    if (L > nodeR || R < nodeL) return 0;
    if (L <= nodeL &&  R >= nodeR) return seg[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L,R,nodeNum*2,nodeL,mid) + sum(L,R,nodeNum*2+1,mid+1,nodeR);
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        S = 1;
        while (S < n + m)
            S *= 2;
        seg.resize(S*2);
        id.resize(n + 1);
        fill(seg.begin(), seg.end(), 0);
        for (int i = 0; i < n; i++) {
            seg[S + i] = 1;
            id[i + 1] = n - i;
        }
        for (int i = S - 1; i > 0; i--)
            seg[i] = seg[i*2] + seg[i*2+1];
        int cnt = n;
        while (m--) {
            cin >> x;
            cout << sum(id[x] + 1, cnt, 1, 1, S) <<' ';
            update(id[x], 0);
            id[x] = ++cnt;
            update(id[x],1);
        }
        cout << '\n';
    }


}
/*
1. 영화 수집
    - 엄청 어려운듯.
    - 이미 1이 존재하니까 제일 위를 0 -1 이렇게 줄여가면서 자기 보다 작은 값들의 갯수가 자기가 올라가야할 갯수 인것 같음.
    - 솔직히 -를 처리하기 힘드니까, n , n- 1, n-2... 1 을 1 2,3,4,5 이렇게 할당하고 자기보다 큰값들의 갯수가 자기가 가야할 구간의 갯수라고 하면 될듯.
    - 그러면 최대 n+m만큼 높이가 생길 수 있으니 이를 MAX로 잡고 구하면 될듯?
*/