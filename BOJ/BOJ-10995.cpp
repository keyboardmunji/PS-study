// Authored by : keyboardmunji
// Created on 2025-08-08.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i =0; i< n;i++) {
        if (i % 2)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << "* ";
        cout <<'\n';
    }
}
/*
1. 별찍기 - 20
    - 쉬운 문제.
*/