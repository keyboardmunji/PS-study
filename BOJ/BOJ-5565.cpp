// Authored by : keyboardmunji
// Created on 2025-08-23.
#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int a,b = 0,x;
    cin >> a;
    for (int i =0;i < 9; i++) {
        cin >> x;
        b += x;
    }
    cout << a - b;
}
/*
1. 영수증
*/