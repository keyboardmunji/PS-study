// Authored by : keyboardmunji
// Created on 2025-04-25.
#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d;
    int x = b*c + a*d;
    int y = b*d;
    int z = gcd(x,y);
    cout << x/z << ' ' << y / z;
    return 0;
}
/*
0. int overflow는 안걸림.
1. 통분해서 구한뒤, 최대공약수로 분자 분모를 나누면 됨.
*/