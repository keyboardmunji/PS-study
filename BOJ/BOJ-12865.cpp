// Authored by : keyboardmunji
// Created on 2025-06-02.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,k;
pair<int,int> item[101];
int d[101][100001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i =1;i <= n;i++) cin >> item[i].X >> item[i].Y;
    sort(item,item+n);

    for (int i = 1; i<= n;i++) {
        for (int j =1; j <= k;j++) {
            if (item[i].X <= j)
                d[i][j] = max(d[i-1][j], d[i-1][j - item[i].X] +item[i].Y);
            else
                d[i][j] = d[i-1][j];
        }
    }
    cout << d[n][k];
}
/*
1. 평범한 배낭
    - 무게 기준 오름차순 sort함.
    - d[i][j] = i번째의 물건을 가지고 있을 때, j의 무게의 경우 최대 가치.
*/
