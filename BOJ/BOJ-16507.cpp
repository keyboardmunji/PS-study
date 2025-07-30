// Authored by : keyboardmunji
// Created on 2025-07-30.
#include <bits/stdc++.h>
using namespace std;

int r,c,q,x;
int r1,c1,r2,c2;
int sum[1001][1001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> q;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c;j++) {
            cin >> x;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x;
        }
    }
    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) <<'\n';
    }
}
/*
1. 어두운 건 무서워.
    - 2차원 Prefix Sum 문제.
*/