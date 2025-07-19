// Authored by : keyboardmunji
// Created on 2025-07-20.
#include <bits/stdc++.h>
using namespace std;

int x, n;
int arr[250001];
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> n;
    for(int i = 1 ;i <=x;i++) cin >> arr[i];
    int sum = 0, cnt = 1, mx = 0;
    for (int i = 1; i <= x;i++) {
        if (i <= n) {
            sum += arr[i];
            mx = sum;
        }else {
            sum += arr[i] - arr[i-n];
            if (mx == sum)
                cnt++;
            else if (mx < sum) {
                cnt = 1;
                mx = sum;
            }
        }
    }
    if (mx == 0)
        cout << "SAD";
    else
        cout << mx << '\n' << cnt;
}

/*
1. 블로그
    - 슬라이딩 윈도우 연습하기.
    - 전형적인 슬라이딩 윈도우 문제.
*/