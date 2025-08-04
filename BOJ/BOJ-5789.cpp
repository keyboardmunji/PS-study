// Authored by : keyboardmunji
// Created on 2025-08-04.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int len = s.length();
        bool flag;
        for (int i =0; i < len/2;i++) {
            if (s[i] == s[len - i - 1]) flag = true;
            else flag = false;
        }
        if (flag) cout << "Do-it\n";
        else cout << "Do-it-Not\n";
    }
}
/*
1. 한다 안한다.
*/