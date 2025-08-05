// Authored by : keyboardmunji
// Created on 2025-08-05.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2,s,ss;
    cin >> s1 >> s2;
    for (int i =0; i<8;i++) {
        s += s1[i];
        s += s2[i];
    }
    for (int i = 0; i < 14;i++) {
        for (int j = 0; j < 16 - i - 1; j++)
            ss += char(((s[j] - '0' + s[j + 1] - '0') % 10) + '0');
        s = ss;
        ss.clear();
    }
    cout << s;
}
/*
1. 핸드폰 궁합.
*/