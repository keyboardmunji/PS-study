// Authored by : keyboardmunji
// Created on 2025-08-19.
#include <bits/stdc++.h>
using namespace std;

int cnt,n,m = 0;

void cut(int x,int y) {
    if (x == 1 && y == 1)
        return;
    if (x >= y) {
        cut(x/2,y);
        cut(x - (x/2),y);
    }else {
        cut(x,y/2);
        cut(x,y - (y/2));
    }
    cnt++;
}
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cut(n,m);
    cout << cnt;
}
/*
1. 초콜릿 자르기.
    - 재귀로 다 잘라버리면 됨.
    - 이지할듯.
*/