// Authored by : keyboardmunji
// Created on 2025-08-17.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,cnt = 0;
    cin >> n;
    for (int i = 1 ; i<= n; i++) {
        int k = i,sum =0;
        while (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        if (i % sum == 0) cnt++;
    }
    cout << cnt;
}
/*
1. 신기한 수
*/