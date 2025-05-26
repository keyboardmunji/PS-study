// Authored by : keyboardmunji
// Created on 2025-05-26.
#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n>> m;
        int r = min(n,m-n);
        long long res = 1;
        for (int i =1;i<=r;i++) {
            res *= m-i+1;
            res /= i;
        }
        cout << res <<'\n';
    }

    return 0;
}
/*
1. 이거, 1~m까지 n개를 고르는데, 뒤에 숫자가 크게끔하는 백트래킹이랑 동일한 문제로 치환됨.
2. 근데, TLE에 걸림. -> 걍 mCn구하는 문제임.
*/