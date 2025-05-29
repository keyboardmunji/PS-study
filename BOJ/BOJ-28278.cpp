// Authored by : keyboardmunji
// Created on 2025-05-29.
#include <bits/stdc++.h>
using namespace std;

int n,num,q;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    stack <int> s;
    while (n--) {

        cin >> q;
        if (q == 1) {
            cin >> num;
            s.push(num);
        }else if (q == 2) {
            if (s.empty())
                cout << -1 <<'\n';
            else {
                cout << s.top() <<'\n';
                s.pop();
            }
        }else if (q == 3)
            cout << s.size() <<'\n';
        else if (q == 4) {
            if (s.empty())
                cout << 1 <<'\n';
            else
                cout << 0 <<'\n';
        }else if (q == 5) {
            if (s.empty())
                cout << -1 <<'\n';
            else
                cout << s.top() <<'\n';
        }
    }
    return 0;
}
/*
1.
*/