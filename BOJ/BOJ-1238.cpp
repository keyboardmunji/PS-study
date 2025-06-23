// Authored by : keyboardmunji,
// Created on 2025-06-23.
#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000000;
int n,m,x,a,b,c;
vector<vector<int>> val(1001,vector<int>(1001,MAX));

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i<m;i++) {
        cin >> a>> b >> c;
        val[a][b] = c;
    }
    for (int i = 1;i<=n;i++) val[i][i] = 0;

    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++)
            for (int k = 1; k<=n;k++)
                if (val[j][k] > val[j][i] + val[i][k]) val[j][k] = val[j][i] + val[i][k];
    int ans = 0;
    for (int i = 1;i<=n;i++)
        ans = max(ans,val[i][x] + val[x][i]);
    cout << ans;
}
/*
문제 : 파티
    - 문제만 보면 플로이드 알고리즘 쓰는 것 같음.
*/
