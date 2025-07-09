// Authored by : keyboardmunji
// Created on 2025-07-09.
#include <bits/stdc++.h>
using namespace std;

int l;
string s;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> s;
    vector<int> f(l);
    int j = 0;
    for (int i = 1; i < l;i++) {
        while (j > 0 && s[i] != s[j]) j = f[j-1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    cout << l - f[l-1];
    return 0;
}
/*
1. 광고
    - kmp 실패함수에서 어짜피 반복되니까, 뒤에 접두사의 길이가 남아 있을 거임.
    - 그걸 n에 빼주면 답인듯.
*/