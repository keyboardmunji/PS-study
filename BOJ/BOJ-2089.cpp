// Authored by : keyboardmunji
// Created on 2025-05-22.
#include <bits/stdc++.h>
using namespace std;

bool v[40];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,i=0;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    while (n != 0) {
        int k = n%-2;
        n /= -2;
        if (k == -1) {
            n+=1;
            k = 1;
        }
        v[i++] = k;
    }
    for (int j = i-1; j >= 0; j--)
        cout << v[j];
    return 0;
}
/*
1. -2의 나머지가 0 or -1이기에 -1처리가 핵심인 문제.
*/