// Authored by : keyboardmunji
// Created on 2025-04-26.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr1[100001];
int arr2[100001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i= 0;i<n;i++) {
        cin >> arr1[i];
        if (i > 0)
            arr2[i-1] = arr1[i] - arr1[i-1];
    }
    int g = arr2[0];
    for (int i = 1;i<n-1;i++)
        g = gcd(g,arr2[i]);
    int sum = 0;
    for (int i =0;i<n-1;i++)
        sum += (arr2[i]/g) - 1;
    cout << sum;
    return 0;
}
/*
0. 정렬된 형태로 주어짐.
1. 각 사이의 값들의 최대 공약수를 구하면 그게 최대 간격임.
    why? 각 사이에 "동등한 간격으로" 나무를 심는 것은 나누기와 같음.
2. 따라서 각 간격들의 최대 공약수를 구해줌.
3. 그 후 간격들을 최대 공약수로 나누어 준 후 몫에 -1 을 하면 그 위치에서 심어야하는 나무의 개수임.
*/