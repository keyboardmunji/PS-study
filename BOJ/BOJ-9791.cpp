// Authored by : keyboardmunji
// Created on 2025-05-13.
#include <bits/stdc++.h>
using namespace std;

string s;

int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> s;
        if (s == "0") break;
        int cnt = 1,len = s.length();
        char n = s[0];
        for (int i = 1;i<len;i++) {
            if (s[i] != s[i - 1]) {
                cout << cnt << n;
                cnt = 1;
                n = s[i];
            }else
                cnt++;
        }
        cout << cnt << n <<'\n';
    }

    return 0;
}
/*
1.
*/