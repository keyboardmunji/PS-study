// Authored by : keyboardmunji
// Created on 2025-07-21.
#include <bits/stdc++.h>
using namespace std;

int n,m,l,r;
int arr[100001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n;i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    cin >> m;
    while (m--) {
        cin >> l >> r;
        cout << arr[r] - arr[l-1] <<'\n';
    }

}
/*
1. 합 구하기
    - 단순 누적합.
*/