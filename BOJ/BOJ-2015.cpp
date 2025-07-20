// Authored by : keyboardmunji
// Created on 2025-07-20.
#include <bits/stdc++.h>
using namespace std;

long long n,k;
int arr[200001];
unordered_map<long long,int> mp;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1 ; i <= n ;i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    long long ans = 0;
    mp[0] = 1;
    for (int i = 1; i<=n;i++) {
        long long x = arr[i] - k;
        if (mp.count(x))
            ans += mp[x];
        mp[arr[i]]++;
    }
    cout << ans;
}
/*
1. 수들의 합 4
    - prefix sum
*/