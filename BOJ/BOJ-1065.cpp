// Authored by : keyboardmunji
// Created on 2025-08-10.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    for (int i = 1;i <= n; i++) {
        bool chk = true;
        int d = i / 10, k = i % 10;
        int t = (d % 10) - k;
        while (d > 0) {
            if ((d % 10) - k == t) {
                k = d % 10;
                d /= 10;
                continue;
            }
            chk = false;
            break;
        }
        if (chk)
            cnt++;
    }
    cout << cnt;
}
/*
1. 한수
*/