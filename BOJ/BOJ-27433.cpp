// Authored by : keyboardmunji
// Created on 2025-05-15.
#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    long long d[21] = {1,};
    for (int i = 1;i<=20;i++)
        d[i] = d[i-1] * i;
    cin >> n;
    cout << d[n];

    return 0;
}
/*
1
*/