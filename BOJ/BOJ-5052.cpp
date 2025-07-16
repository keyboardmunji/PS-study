// Authored by : keyboardmunji
// Created on 2025-07-17.
#include <bits/stdc++.h>
using namespace std;

int t,n;
const int ROOT = 1;
const int MX = 10000*10+5;
int unused = 2;
bool chk[MX];
int used[MX][10];

int c2i(char ch) {
    return ch - '0';
}

void insert(string &s) {
    int cur = ROOT;
    for (auto c : s) {
        if (used[cur][c2i(c)] == -1)
            used[cur][c2i(c)] = unused++;
        cur = used[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string &s) {
    int cur = ROOT;
    for (auto c : s) {
        if (chk[cur] == true)
            return true;
        if (used[cur][c2i(c)] == -1)
            return false;
        cur = used[cur][c2i(c)];
    }
    return true;
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        for (int i = 0; i<MX;i++)
            fill(used[i],used[i] + 10,-1);
        fill(chk,chk+MX,false);
        unused = 2;
        cin >> n;
        string s;
        bool chk1 = false;
        for (int i = 0 ; i<n;i++) {
            cin >> s;
            if (find(s))
                chk1 = true;
            insert(s);
        }
        if (chk1)
            cout <<"NO\n";
        else
            cout << "YES\n";
    }
}

/*
1. 전화번호 목록
    - 트라이로 find하고 insert하면 될듯. 대신 find할때 안되는 경우엔, NO출력하고 case넘기면 됨.
*/