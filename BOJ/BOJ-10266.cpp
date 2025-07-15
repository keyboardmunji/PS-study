// Authored by : keyboardmunji
// Created on 2025-07-15.
#include <bits/stdc++.h>
using namespace std;

int n,x;
int a[400001];
int b[200001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0 ; i<n;i++) cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i <n;i++)
        a[n+i] = a[i];
    for (int i = 0; i < 2 *n - 1;i++)
        a[i] = a[i] < a[i+1] ? a[i+1] - a[i] : 360000 - a[i] + a[i+1];

    for (int i = 0; i<n;i++)
        cin >> b[i];
    sort(b,b+n);
    for (int i = 0; i<n - 1;i++)
        b[i] = b[i + 1] - b[i];

    vector<int> f(n - 1);
    int j = 0;
    for (int i = 1; i < n - 1; i++) {
        while (j > 0 && b[i] != b[j]) j = f[j-1];
        if (b[i] == b[j]) f[i] = ++j;
    }
    j = 0;
    for (int i = 0;i<2*n-1;i++) {
        while (j > 0 && a[i] != b[j]) j = f[j-1];
        if (a[i] == b[j]) j++;
        if (j == n -1) {
            cout <<"possible";
            return 0;
        }
    }
    cout <<"impossible";
}

/*
1. 시계 사진들
    - 간격 일치하는지 확인하면되는 kmp문제임.
    - 대략 O(3n)에 해결됨.
*/