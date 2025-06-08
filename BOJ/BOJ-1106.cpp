// Authored by : keyboardmunji,
// Created on 2025-06-08.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int c, n;
pair<int,int> arr[21];
int d[2][1000001];
int mn = 1000000;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> n;
    for (int i= 1; i<= n; i++)
        cin >> arr[i].X >> arr[i].Y; //  x : 비용, y : 사람
    sort(arr + 1,arr+n + 1);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j <= mn;j++) {
            if (j >= arr[i].X)
                d[1][j] = max(d[1][j - arr[i].X] + arr[i].Y, d[0][j]);
            else
                d[1][j] = d[0][j];
            if (d[1][j] >= c) {
                mn = min(mn,j);
                break;
            }
        }
        for (int j = 1;j <= mn; j++)
            d[0][j] = d[1][j];
    }
    cout << mn;
}
/*
1. 호텔
    - 비용 , 고객 -> 비용이작고, 고객이 많을 수록 홍보효과가 좋은건 당연함.
    - dp로 풀면 좋을듯. 왜냐면 정수끼리 나누어서 어느 비율이 더 좋은지 확인하기도 힘듬.
    - 그 다음으로 가장 효율이 좋은것만 선택했을 때 최고라는 보장이 없음. 왜냐면 최소 c명이라는 조건이 있기 때문.
    - 따라서 배낭 문제로 치환하면 좋을듯.
    - 비용당 사람으로 해야, 비용이 정확하게 안맞아도 사람수는 최대로 보장되게 만들 수 있음.
*/
