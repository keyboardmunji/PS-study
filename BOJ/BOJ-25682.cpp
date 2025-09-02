#include <bits/stdc++.h>

using namespace std;

int n,m,k,a1, a2;
int maap[2001][2001];
int sum1[2001][2001];
int sum2[2001][2001];

string s[2001];

int mn = 2000 * 2000;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // 입력
    cin >> n >> m>> k;
    for (int i = 0; i <n; i++) cin >> s[i];
    if (k == 1) {
        cout << 0;
        return 0;
    }
    if (k % 2) {
        a2 = (k * k) / 2;
        a1 = (k * k) - a2;
    }else {
        a1 = a2 = (k * k) / 2;
    }
    // 0,1 배열로 전환.
    for (int i = 0; i < n;i++) {
        for (int j =0;j < m;j++) {
            maap[i + 1][j + 1] = (s[i][j] == 'B' ? 1 : 0);
        }
    }
    // prefix Sum 시작.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 && j % 2 || i % 2 == 0 && j % 2 == 0)
                sum1[i][j] = maap[i][j];
            else
                sum2[i][j] = maap[i][j];
            sum1[i][j] += sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
            sum2[i][j] += sum2[i][j - 1] + sum2[i - 1][j] - sum2[i - 1][j - 1];
        }
    }
    // 각 상황마다 O(1)에 판단.
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            int s1 = sum1[i + k - 1][j + k - 1] - sum1[i + k - 1][j - 1] - sum1[i - 1][j + k - 1] + sum1[i - 1][j - 1];
            int s2 = sum2[i + k - 1][j + k - 1] - sum2[i + k - 1][j - 1] - sum2[i - 1][j + k - 1] + sum2[i - 1][j - 1];
            int mn1,mn2;
            if (i % 2 && j % 2 || i % 2 == 0 && j % 2 == 0) {
                mn1 = (a1 - s1) + s2;
                mn2 = s1 + (a2 - s2);
            }else {
                mn1 = (a2 - s1) + s2;
                mn2 = s1 + (a1 - s2);
            }
            mn = min({mn,mn1,mn2});
        }
    }
    cout << mn;
    return 0;
}
