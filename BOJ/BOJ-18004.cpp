// Authored by : keyboardmunji
// Created on 2025-05-13.
#include <bits/stdc++.h>
using namespace std;

int a,b;
int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    int cnt = 0;
    while (a > b) {
        if (a % 2) a++;
        else a/=2;
        cnt++;
    }
    cout << cnt + b - a;

    return 0;
}
/*
1. 작아지는 방법 -> 2나누기
2. 커지는 방법 -> + 1
근데, 커진 상태에서 2나눈거랑, 작아진 상태에서 1을 더하는 것이랑 둘중 뭐가 좋음?
작아지고 더하는게 2배의 효율
*/