// Authored by : keyboardmunji
// Created on 2025-07-22.
#include <bits/stdc++.h>
using namespace std;

int n,x;
int arr[301][301];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            cin >> x;
            arr[i][j] = x + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    int ans = -1000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k<=n;k++) {
                int x1 = j + i - 1;
                int y1 = k + i - 1;
                if (x1 > n || y1 > n) continue;
                ans = max(ans,arr[x1][y1] - arr[x1][k - 1] - arr[j - 1][y1] + arr[j-1][k-1]);
            }
        }
    }
    cout << ans;
}
/*
1. 사과나무
    - 2차원 Prefix Sum 연습.
    - 일단 2차원 sum 배열을 만듬.
    - 1 ~ 300 까지 거의 n^3으로 돌리면 될듯.
*/