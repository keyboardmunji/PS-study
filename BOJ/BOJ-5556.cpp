// Authored by : keyboardmunji
// Created on 2025-05-05.
#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[3] = {3,1,2};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0;i<k;i++) {
        int a,b;
        cin >> a >> b;
        if (a > (n+1)/2)
            a = n + 1 - a;
        if (b > (n+1)/2)
            b = n + 1 - b;
        cout << arr[min(a,b)%3] <<'\n';
    }

    return 0;
}
/*
1. 2사분면만 보게끔 변경함. -> 종이 접기 느낌?
*/