// Authored by : keyboardmunji
// Created on 2025-07-19.
#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vector<int> v(n);
    for (int i =0; i<n;i++)
        cin >> v[i];
    int sum = 0; // int overflow는 없음.
    for (int i =0 ;i < k;i++)
        sum += v[i];
    int mx = sum;
    for (int i = k; i < n;i++) {
        sum += v[i] - v[i-k];
        mx = max(mx, sum);
    }
    cout << mx;
}

/*
1. 수열
    - 슬라이딩 윈도우 공부하기.
*/