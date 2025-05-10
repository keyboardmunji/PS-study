// Authored by : keyboardmunji
// Created on 2025-05-10.
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> users;
int cnt,n;
string s;
int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "ENTER")
            users.clear();
        else if (users.find(s) == users.end()) {
            cnt++;
            users.insert(s);
        }
    }
    cout << cnt;

    return 0;
}
/*
1.
*/