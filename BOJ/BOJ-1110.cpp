// Authored by : keyboardmunji
// Created on 2025-07-29.
#include <bits/stdc++.h>
using namespace std;

int n,n1,cnt;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    n1 = n;
    do {
        int x = n1 / 10 + n1 % 10;
        n1 = (n1 % 10) * 10 + x % 10;
        cnt++;
    }while (n1 != n);
    cout << cnt;
}
/*
1. 더하기 사이클
    - 문제에 주어진 대로 구현만 하면 되는 문제.
*/