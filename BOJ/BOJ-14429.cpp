// Authored by : keyboardmunji
// Created on 2025-05-19.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, m=20000, t = 1,idx;
    cin >> n;
    while (t <= n) {
        int a,b;
        cin >> a >> b;
        int r = ((a-1)/(b+1) + 1)*2;
        if (r < m) {
            m = r;
            idx = t;
        }
        t++;
    }
    cout << idx <<' ' << m;
    return 0;
}
/*
1. j-1 % m + 1을 구함. -> 이걸 말하면 이김.
2. m+1로 나눈 몫 ->
*/