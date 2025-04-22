// Authored by : keyboardmunji
// Created on 2025-04-22.
#include <bits/stdc++.h>
using namespace std;

int n;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int cnt = 0;
    for (int i= 1;i*i<=n;i++)
        cnt++;
    cout << cnt;
    return 0;
}
/*
1. 약수의 개수가 홀수 인것만 열려있음. 즉, 제곱수만 쳐내면 됨.
*/