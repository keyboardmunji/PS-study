// Authored by : keyboardmunji
// Created on 2025-04-24.
#include <bits/stdc++.h>
using namespace std;

string s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    sort(s.begin(),s.end(),greater<char>());
    cout << s;

    return 0;
}
/*
1. 스트링 정렬
*/