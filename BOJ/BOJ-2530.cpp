// Authored by : keyboardmunji
// Created on 2025-08-15.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    c += d;
    if (c >= 60) {
        b += c / 60;
        c %= 60;
    }
    if (b >= 60) {
        a += b / 60;
        b %= 60;
    }
    a = a % 24;
    cout << a <<' ' << b <<' ' << c;
}
/*
1. 인공지능 시계
*///
// Created by ASUS on 25. 8. 15.
//
