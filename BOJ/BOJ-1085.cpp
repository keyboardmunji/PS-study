// Authored by : keyboardmunji
// Created on 2025-04-13.
#include <bits/stdc++.h>
using namespace std;

int x,y,w,h;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y >> w >> h;
    cout << min({x,y,w-x,h-y});
    return 0;
}



