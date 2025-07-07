// Authored by : keyboardmunji
// Created on 2025-07-07.
#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string &s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1;i<s.size();i++) {
        while (j > 0 && s[j] != s[i]) j = f[j-1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    string t,p;
    getline(cin,t);
    getline(cin,p);
    vector<int> f = failure(p);
    int j = 0;
    vector<int> ans;
    for (int i = 0; i < t.size();i++) {
        while (j > 0 && t[i] != p[j]) j = f[j-1];
        if (t[i] == p[j]) j++;
        if (j == p.size()) {
            ans.push_back(i - j + 2);
            j = f[j - 1];
        }
    }
    cout << ans.size() <<'\n';
    for (auto c : ans) cout << c <<' ';
    return 0;
}
/*
1. 찾기
    - KMP 알고리즘 연습하기 + 몇번 등장하는지 체크하기.
*/