// Authored by : keyboardmunji
// Created on 2025-08-09.
#include <bits/stdc++.h>
using namespace std;

int arr[101];
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i =0;i<n;i++)
        cin >> arr[i];
    int mx = *max_element(arr,arr+n);
    int mn = *(min_element(arr,arr+n));
    if (arr[0] == mx)
        cout << "hard";
    else if (arr[0] == mn)
        cout << "ez";
    else
        cout << "?";
}
/*
1. 첫 번째 문제는 정말 쉬운 문제일까?
*/