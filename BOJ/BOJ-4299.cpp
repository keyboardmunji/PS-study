// Authored by : keyboardmunji
// Created on 2025-08-06.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 || a < b) {
        cout << -1;
        return 0;
    }
    cout << (a + b) / 2 <<' ' << (a-b) / 2;
}
/*
1. AFC 윔블던
    - p + q = a, p - q = b
*/