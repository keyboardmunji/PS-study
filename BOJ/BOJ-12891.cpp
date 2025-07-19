// Authored by : keyboardmunji
// Created on 2025-07-20.
#include <bits/stdc++.h>
using namespace std;

int p,s,a,c,g,t,cnt;
int chk[4];
string pw;

int func(int i) {
    if (pw[i] == 'A')
        return 0;
    if (pw[i] == 'C')
        return 1;
    if (pw[i] == 'G')
        return 2;
    if (pw[i] == 'T')
        return 3;
}
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p >> s >> pw >> a >> c >> g >> t;

    for (int i = 0; i < s; i++)
        chk[func(i)]++;
    for (int i = s; i < p;i++) {
        if (chk[0] >= a && chk[1] >= c && chk[2] >= g && chk[3] >= t)
            cnt++;
        chk[func(i-s)]--;
        chk[func(i)]++;
    }
    if (chk[0] >= a && chk[1] >= c && chk[2] >= g && chk[3] >= t)
        cnt++;
    cout << cnt;
}

/*
1. DNA 비밀번호
    - 슬라이딩 윈도우 연습하기.
    - O(S)로 해결할 수 있음.
*/