// Authored by : keyboardmunji
// Created on 2025-08-28.
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;
    cin >> a >> b >> c;
    cout << a + b + c - min({a,b,c}) - max({a,b,c});

}
/*
1. 세수
    - 세수 ㄱㄱ
*/