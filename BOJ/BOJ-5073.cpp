// Authored by : keyboardmunji
// Created on 2025-05-18.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int a,b,c;
        cin >> a >> b>> c;
        if (a == 0 && b== 0 && c == 0)
            return 0;
        if (max({a,b,c}) * 2 - a- b- c >= 0) {
            cout <<"Invalid\n";
        }
        else if (a== b && b== c)
            cout <<"Equilateral\n";
        else if (a==b || b==c || c== a)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
    return 0;
}
/*
1.
*/