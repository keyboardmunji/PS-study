// Authored by : keyboardmunji
// Created on 2025-08-01.
#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*')
            cnt = i;
        else {
            if (i % 2)
                sum += (s[i] - '0') * 3;
            else
                sum += s[i] - '0';
        }
    }
    for (int i = 0; i < 10; i++) {
        if ((i * (cnt % 2 == 1 ? 3 : 1) + sum) % 10 == 0) {
            cout << i;
            return 0;
        }
    }
}
/*
1. ISBN
    - 쉬운 문제.
*/