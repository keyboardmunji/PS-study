// Authored by : keyboardmunji
// Created on 2025-04-23.
#include <bits/stdc++.h>
using namespace std;

int n;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        bool ch = true;
        cin >> n;
        if (n == 0 || n == 1) {
            cout << 2 <<'\n';
            continue;
        }
        while (ch) {
            ch = false;
            for (long long i=2;i*i<=n;i++) {
                if (n % i == 0) {
                    ch = true;
                    break;
                }
            }
            n++;
        }
        cout << n - 1 <<'\n';
    }
    return 0;
}
/*
1. 일단 시간복잡도 생각하지않고 소수판별하기.
2. 에라토네스 체는 시간복잡도 백퍼센트 넘어감.
*/