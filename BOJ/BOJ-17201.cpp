// Authored by : keyboardmunji
// Created on 2025-04-14.
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for (int i = 0;i < n*2 - 1;i++) {
        if (s[i] != s[i + 1])
            continue;
        else {
            cout <<"No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}



