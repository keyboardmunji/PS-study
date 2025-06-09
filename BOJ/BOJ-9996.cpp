// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
using namespace std;

int n;
string a,b,s;
bool ch = true;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '*') {
            ch = false;
            continue;
        }
        if (ch)
            a += s[i];
        else
            b += s[i];
    }
    for (int i = 0; i<n ; i++) {
        cin >> s;
        ch = true;
        if (s.length() >= a.length() + b.length()) {
            for (int j =0; j< a.length();j++) {
                if (s[j] == a[j]) continue;
                ch = false;
            }
            if (ch == true) {
                for (int j = s.length() - b.length(); j < s.length();j++) {
                    if (s[j] == b[j - s.length() + b.length()]) continue;
                    ch = false;
                }
            }
        }else
            ch = false;
        if (ch)
            cout << "DA\n";
        else
            cout << "NE\n";
    }

}
/*
1. 한국이 그리울 땐 서버에 접속하지
    - 별표는 한개만 나옴.
    - 그러면 별표를 기준으로 문자열을 2개로 나누고, 각각 있는지 매칭해보면 됨.
    - 아, 시작과 끝이 일치해야하는구먼.
*/
