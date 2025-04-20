// Authored by : keyboardmunji
// Created on 2025-04-20.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int a,b;
    cin >> a >> b;
    cout << a *b/gcd(a,b);
    return 0;
}
