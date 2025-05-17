// Authored by : keyboardmunji
// Created on 2025-05-17.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;
    cin >> a>> b >> c;
    if (a+b+c == 180) {
        if (a == b && b== c) {
            cout << "Equilateral";
        }else if (a == b || b == c || c == a) {
            cout << "Isosceles";
        }else {
            cout << "Scalene";
        }
    }else
        cout << "Error";
    return 0;
}
/*
1.
*/