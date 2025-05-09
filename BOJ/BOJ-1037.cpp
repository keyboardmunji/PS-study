// Authored by : keyboardmunji
// Created on 2025-05-07.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <long long> v(n);
    for (int i =0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    if (n == 1)
        cout << v[0] * v[0];
    else
        cout << v[0] * v[n-1];
    return 0;
}
/*
1.
*/