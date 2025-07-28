// Authored by : keyboardmunji
// Created on 2025-07-28.
#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,e;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d >> e;
    int n1 = min({a,b,c});
    int n2 = min({d,e});
    cout << n1 + n2 - 50;

}
/*
1. 상근 날드
    - 쉬운문제
*/