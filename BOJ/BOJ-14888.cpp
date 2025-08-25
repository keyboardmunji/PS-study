// Authored by : keyboardmunji
// Created on 2025-08-25.
#include <bits/stdc++.h>

using namespace std;

int n,mx = -1000000001,mn = 1000000001;
int arr1[12],arr2[5];

int cal(int x,int a,int b) {
    if (x == 1) return a + b;
    if (x == 2) return a - b;
    if (x == 3) return a * b;
    if (x == 4) return a / b;

}
void go(int m, int res) {
    if (m == n + 1) {
        mn = min(mn,res);
        mx = max(mx,res);
        return;
    }
    for (int i =1; i<=4; i++) {
        if (arr2[i] > 0) {
            arr2[i]--;
            int t = cal(i,res,arr1[m]);
            go(m + 1, t);
            arr2[i]++;
        }
    }
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n;i++) cin >> arr1[i];
    for (int i = 1; i <= 4; i++) cin >> arr2[i];
    go(2, arr1[1]);
    cout << mx << '\n' << mn;
}
/*
1. 연산자 끼워 넣기.
    - 백트래킹을 이용해봅시다.
*/