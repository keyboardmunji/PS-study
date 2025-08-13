// Authored by : keyboardmunji
// Created on 2025-08-13.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;
    cin >> a >> b >> c;
    int sum = a* b;
    if (c - sum >= 0) cout << 0;
    else
        cout << sum - c;
}
/*
1. 과자
*/