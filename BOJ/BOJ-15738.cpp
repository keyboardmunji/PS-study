// Authored by : keyboardmunji
// Created on 2025-05-06.
#include <bits/stdc++.h>
using namespace std;

int n,k,m;
int arr[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> m;
    for (int i =1;i<=n;i++) cin >> arr[i];
    for (int i = 0;i<m;i++) {
        int q,st = 1,ed = n;
        cin >> q;
        if (q > 0)
            ed = q;
        else
            st = n + q + 1;
        if (k >= st && k <= ed)
            k = st + ed - k;
    }
    cout << k;
    return 0;
}
/*
1. k번째 위치한 수가 m번 연산을 수행한 후 어디 위치해 있을까?

*/