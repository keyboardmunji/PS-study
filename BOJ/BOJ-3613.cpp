// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
using namespace std;

string a;
bool chk1,chk2;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i =0; i<a.length(); i++) {
        if (a[i] == '_')
            chk1 = true;
        else if (a[i] >= 'A' && a[i] <= 'Z')
            chk2= true;
    }
    if (chk1 && chk2) {
        cout << "Error!";
        return 0;
    }
    if (chk2 == true) {
        if (a[0] >= 'A' && a[0] <= 'Z') {
            cout << "Error!";
            return 0;
        }
        for (int i =0; i<a.length(); i++) {
            if (a[i] >= 'A' && a[i] <= 'Z')
                cout <<'_'<< char(a[i] - 'A' + 'a');
            else
                cout << a[i];
        }
    }else {
        if (a[0] =='_' || a[a.length()-1] == '_') {
            cout << "Error!";
            return 0;
        }
        for (int i =0 ;i< a.length() - 1; i++) {
            if (a[i] == '_' && a[i] == a[i+1]) {
                cout << "Error!";
                return 0;
            }
        }
        for (int i =0; i<a.length(); i++) {
            if (a[i] == '_') {
                i++;
                cout << char(a[i] - 'a' + 'A');
            }else
                cout << a[i];
        }
    }
}
/*
1. Java vs C++
    - 에러가 나는 경우 : 대문자와 밑줄이 혼합되어 있을 때, java에서 첫문자가 대문자 일때
    -  c++에서 첫 문자 또는 마지막 문자가 밑줄 일때, 밑줄이 연속으로 나올 때
*/
