// Authored by : keyboardmunji
// Created on 2025-08-20.
#include <bits/stdc++.h>
using namespace std;

int n2i(char c) {
    return c - '0';
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    char c;
    cin >> t;
    while (t--) {
        string q,s;
        int n, k = 0;
        cin >> q >> n >> s;
        vector<int> v;
        for (int i = 1;i < s.length(); i++) {
            if (s[i] == ',' || s[i] == ']') {
                v.push_back(k);
                k = 0;
            }else {
                k *= 10;
                k += n2i(s[i]);
            }
        }
        int st = 0, ed = n;
        bool flag = true;
        for (int i = 0; i < q.size();i++) {
            if (q[i] == 'R') {
                flag = !flag;
            }else {
                if (flag) st++;
                else ed --;
            }
        }
        if (st > ed)
            cout << "error\n";
        else if (st == ed) {
            cout << "[]\n";
        }else{
            cout << '[';
            if (flag) {
                for (int i = st; i < ed - 1;i++)
                    cout << v[i] << ',';
                cout << v[ed - 1];
            }else {
                for (int i = ed - 1; i > st; i--)
                    cout << v[i] << ',';
                cout << v[st];
            }
            cout << "]\n";
        }
    }
}
/*
1. AC
    - 걍 앞에 변수 하나, 뒤에 변수 하나, 방향 전환 관리 bool 챙기고
    - 앞 < 뒤 -> ERROR로 처리하면 끝날듯?
*/