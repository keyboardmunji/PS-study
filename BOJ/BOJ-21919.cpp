// Authored by : keyboardmunji
// Created on 2025-04-21.
#include <bits/stdc++.h>
using namespace std;

long long n,sum = 1;
bool chk[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0;i<n;i++) {
        long long x;
        bool ch = true;
        cin >> x;
        for (long long j = 2; j * j <= x; j++)
            if (x % j == 0) ch = false;
        if (ch && chk[x] == false) {
            sum *= x;
            chk[x] = true;
        }
    }
    if (sum == 1)
        cout << -1;
    else
        cout << sum;
    return 0;
}
/*
1. int overflow 신경안씀
2. 중복이 있는 경우도 있음.. ㄷㄷ;;
10^3 * 10^4 = 10^7 -> 1000만, -> 각각, 소수판별
소수들의 최소 공배수는 짜피 걍 다 곱한거임.
1은 곱해져도 의미가 없어서 따로 예외 처리안함.
*/