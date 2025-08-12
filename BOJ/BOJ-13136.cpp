// Authored by : keyboardmunji
// Created on 2025-08-12.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int r,c,n;
    long long s;
    cin >> r >> c >> n;
    s = r / n;
    if (r % n != 0)
        s++;
    if (c % n == 0)
        cout << s * (c / n);
    else
        cout << s * (c / n + 1);
}
/*
1. Do Not Touch Anything
*/