// Authored by : keyboardmunji
// Created on 2025-07-16.
#include <bits/stdc++.h>
using namespace std;

int n,m;
int root = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
int nxt[MX][26];

int c2i(char c) {
    return c - 'a';
}

void insert(string &s) {
    int cur = root;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
}

bool find(string &s) {
    int cur = root;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return true;
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i<MX;i++)
        fill(nxt[i],nxt[i]+26,-1);
    cin >> n >> m;
    string s;
    for (int i = 0 ;i <n;i++) {
        cin >> s;
        insert(s);
    }
    int cnt = 0;
    while (m--) {
        cin >> s;
        if (find(s))
            cnt++;
    }
    cout << cnt;
}

/*
1. 접두사 찾기
    - 트라이 이용하는 대신, 찾을 떄 chk가 아니더라도 있으면 반복문만 통과하면 되는 듯.
*/