// Authored by : keyboardmunji
// Created on 2025-04-17.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    int arr[1001];
    for (int i =0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n,greater<int>());
    cout << arr[k-1];
    return 0;
}


