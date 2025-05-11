// Authored by : keyboardmunji
// Created on 2025-05-11.
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> users;
int cnt,n;
string x,y;
int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    users.insert("ChongChong");
    for (int i =0;i<n;i++){
        cin >> x >> y;
        if (users.find(x) != users.end() || users.find(y) != users.end()) {
            users.insert(x);
            users.insert(y);
        }
    }
    cout << users.size();

    return 0;
}
/*
1.
*/