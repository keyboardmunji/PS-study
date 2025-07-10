// Authored by : keyboardmunji
// Created on 2025-07-10.
#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> s;
        if (s[0] == '.')
            return 0;
        int j = 0;
        vector<int> f(s.size());
        for (int i = 1; i < s.size();i++) {
            while (j > 0 && s[i] != s[j]) j = f[j-1];
            if (s[i] == s[j]) f[i] = ++j;
        }
        int h = s.size() - f[s.size()-1];
        if (s.size() % h != 0)
            cout << 1 <<'\n';
        else
            cout << s.size() / h <<'\n';
    }
}
/*
1. 문자열 제곱
    - 실패함수의 마지막 인덱스에 들어있는 값을 잘 생각해보면 좋음.
    - n - f[n-1]은 패턴의 최소 주기 길이를 나타냄. 하지만 나누어 떨어지는지 확인은ㅇ 해야함.
*/