// Authored by : keyboardmunji
// Created on 2025-05-03.
#include <bits/stdc++.h>
using namespace std;

int arr[1025][1025];
int sum[1025][1025];
int n,m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0;i<=n;i++) {
        for (int j =0;j<=n;j++) {
            if (i == 0 || j == 0) {
                arr[i][j] = 0;
                continue;
            }
            cin >> arr[i][j];
        }
    }

    for (int i =1;i<=n;i++)
        for (int j = 1;j<=n;j++)
            sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

    for (int i =0;i<m;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] <<'\n';
    }
    return 0;
}
/*
1. (x1,y1) ~ (x2,y2) = (x2,y2) - (x1-1,y2) - (x2, y1-1) + (x1-1+y1-1)
*/