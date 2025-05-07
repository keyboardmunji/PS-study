// Authored by : keyboardmunji
// Created on 2025-05-07.
#include <bits/stdc++.h>
using namespace std;

string s;
unordered_set<string> b;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int len = s.length();
    for (int i = 1;i<=len;i++) {
        for (int j = 0; j <= len - i;j++) {
            string a;
            a.append(s,j,i);
            b.insert(a);
        }
    }
    cout << b.size();
    return 0;
}
/*
1. 해시 집합 이용
2. string append 함수 기억하기.
*/