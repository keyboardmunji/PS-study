#include <bits/stdc++.h>

using namespace std;
const int MAX = 2100000000;
int n;
int arr[501];
int sum[501];
int d[501][501];

int func(int a, int b) {
    if (a == b)
        return 0;

    if (d[a][b] != -1)
        return d[a][b];

    int mn = MAX;
    int s = sum[b + 1] - sum[a];
    for (int i = a; i < b; i++)
        mn = min(mn, func(a, i) + func(i + 1, b) + s);
    d[a][b] = mn;
    return mn;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 501; i++)
            fill (d[i], d[i] + 501, -1);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + arr[i - 1];
        cout << func(0, n - 1) << '\n';
    }

    return 0;
}

/*
 1. 파일 합치기
    - Top-Down DP
*/