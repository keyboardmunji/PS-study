// Authored by : keyboardmunji
// Created on 2025-08-11.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    if (b == 0) {
        cout << c / a << ' ' << (f - d * (c/a)) / e;
    }else {
        for (int i = -999; i <= 999; i++) {
            if ((c - a * i) % b == 0) {
                int y = (c - a * i) / b;
                if (d * i + e * y == f) {
                    cout << i << ' ' << y;
                    return 0;
                }
            }
        }
    }
}
/*
1. 수학은 비대면 강의 입니다.
*/