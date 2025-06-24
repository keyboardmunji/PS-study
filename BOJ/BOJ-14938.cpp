// Authored by : keyboardmunji,
// Created on 2025-06-24.
#include <bits/stdc++.h>

using namespace std;
const int MAX = 2000;
int n,m,r,a,b,w;
int val[101];
vector<vector<int>> v(101,vector<int>(101,MAX));

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for (int i = 1;i <= n;i++) cin >> val[i];
    for (int i =0 ;i<r;i++) {
        cin >> a >> b >> w;
        v[a][b] = min(v[a][b],w);
        v[b][a] = min(v[b][a],w);
    }
    for (int i = 1;i<=n;i++) v[i][i] = 0;

    for (int i = 1; i<=n;i++)
        for (int j = 1;j<=n;j++)
            for (int k = 1;k<=n;k++)
                v[j][k] = min(v[j][k], v[j][i] + v[i][k]);

    int ans = 0;
    for (int i = 1;i<=n;i++) {
        int sum = 0;
        for (int j = 1;j<=n;j++) {
            if (v[i][j] > m) continue;
            sum += val[j];
        }
        ans = max(ans,sum);
    }
    cout << ans;
}
/*
문제 : 서강 그라운드
    - 각지역으로 떨어졌을 때 떨어진 지역으로 부터 각지역의 최단 거리를 구함.
    - 최단 거리가 수색범위보다 작을 때 sum을 더해주며, 이를 n번 반복하면 됨.
*/
