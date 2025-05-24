// Authored by : keyboardmunji
// Created on 2025-05-24.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long mul = 1;
    for (int i =1;i<=n;i++) mul *= i;
    cout << mul;

    return 0;
}