// Authored by : keyboardmunji
// Created on 2025-08-26.
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long cnt;
int arr[1000001];
int sum[1000001];
long long m_chk[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = (sum[i - 1] + arr[i]) % m;
        m_chk[sum[i]]++;
        if (sum[i] == 0) cnt++;
    }

    for (int r = 0; r < m; r++) {
        if (m_chk[r] > 1) {
            cnt += m_chk[r] * (m_chk[r] - 1) / 2;
        }
    }

    cout << cnt;
}
/*
1. 나머지 합
*/