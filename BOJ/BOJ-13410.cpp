// Authored by : keyboardmunji
// Created on 2025-08-16.
#include <bits/stdc++.h>
using namespace std;

int rev(int x) {
    int res = 0;
    while (x > 0) {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,mx = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int m = i * n;
        mx = max(mx, rev(m));
    }
    cout << mx;
}
/*
1. 거꾸로 구구단
*/