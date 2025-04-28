// Authored by : keyboardmunji
// Created on 2025-04-28.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i =0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        cout << gcd(x,y) <<'\n';
    }

    return 0;
}
/*
1. gcd 구하기.
*/