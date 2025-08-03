// Authored by : keyboardmunji
// Created on 2025-08-03.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        while (n >= 5) {
            n -= 5;
            cout << "++++ ";
        }
        while (n--) {
            cout << '|';
        }
        cout <<'\n';
    }
}
/*
1. 개표
    - 쉬운 문제.
*/