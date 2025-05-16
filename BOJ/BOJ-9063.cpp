// Authored by : keyboardmunji
// Created on 2025-05-16.
#include <bits/stdc++.h>
using namespace std;
int n,minX = 10001,minY=10001,maxX=-10001,maxY=-10001;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        minX = min(x,minX);
        maxX = max(x,maxX);
        minY = min(y,minY);
        maxY = max(y,maxY);
    }
    if (minX == maxX || minY == maxY) {
        cout << 0;
        return 0;
    }
    cout << (maxX - minX)*(maxY - minY);
    return 0;
}
/*
1.
*/