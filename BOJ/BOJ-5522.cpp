// Authored by : keyboardmunji
// Created on 2025-07-13.
#include <bits/stdc++.h>
using namespace std;

int sum;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i<5;i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum;
}

/*
1. 카드게임
    - 반복문으로 받고 더하기.
*/