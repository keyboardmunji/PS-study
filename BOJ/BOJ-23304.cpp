// Authored by : keyboardmunji,
// Created on 2025-06-10.
#include <bits/stdc++.h>

using namespace std;

string s;

bool func1(string a) {
    if (a.length() == 1)
        return true;
    else {
        int len = a.length();
        for (int i =0; i<len/2;i++) {
            if (a[i] == a[len - i - 1]) continue;
            return false;
        }
        string s1,s2;
        int l = len /2;
        for (int i =0; i< l;i++)
            s1 += s[i];
        for (int i = s.length() - l; i<s.length();i++)
            s2 += s[i];
        if (func1(s1) && func1(s2))
            return true;
        else
            return false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    if (func1(s))
        cout << "AKARAKA";
    else
        cout << "IPSELENTI";
}
/*
1. 아카라카
    - 펠린드롬 판단하는 함수 하나 만들고
    - 1. 주어진 문자열이 팰린드롬인지 확인한다.
    - 2. 주어진 문자열을 [S/2]로 분할 한 후 아카라카 팰린드롬인지 확인한다. 그러면 재귀로 해야지.
*/
