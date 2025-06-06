// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
using namespace std;

long long a1,b1,a2,b2,a3,b3;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    long long ch = b3*(a2-a1) -(b2-b1)*(a3-a1) - b1*(a2-a1);
    if (ch > 0)
        cout << 1;
    else if (ch == 0)
        cout << 0;
    else
        cout << -1;
}
/*
1. CCW
    - 직선으로 따져야하고, x,y로 따지면 안됨.
    - 점과 직선사이의 거리가 양의 방향이면 반시계, 음의 방향이면 시계, 0이면 일직선일듯.
*/
