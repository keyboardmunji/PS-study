// Authored by : keyboardmunji
// Created on 2025-07-22.
#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,k;
int arr[100002];
int d[100002];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i<=n;i++)
        cin >> d[i];
    for (int i =1 ; i<=n;i++)
        arr[i] = d[i] - d[i-1];
    for (int i = 1;i<=m;i++) {
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b+1] -= k;
    }
    for (int i = 1;i<=n;i++) {
        arr[i] += arr[i-1];
        cout << arr[i] <<' ';
    }
}
/*
1. 태상이의 훈련소 생활
    - 차분배열 연습.
*/