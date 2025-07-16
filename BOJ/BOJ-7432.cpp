// Authored by : keyboardmunji
// Created on 2025-07-17.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
const int ROOT = 1;
const int MX = 500 * 40 + 5;
int unused = 2;
int dep[MX];
unordered_map<string,int> used[MX];
string name[MX];

void insert(vector<string>& s) {
    int cur = ROOT,cnt = 0;
    for (auto c : s) {
        int idx = used[cur][c];
        if (idx == 0)
            idx = used[cur][c] = unused++;
        dep[idx] = dep[cur] + 1;
        cur = idx;
        name[idx] = c;
    }
}

void dfs(int t) {
    if (t != ROOT) {
        for (int i = 0 ; i<dep[t];i++) cout << ' ';
        cout << name[t] <<'\n';
    }
    vector<pair<string,int>> s(used[t].begin(), used[t].end());
    sort(s.begin(), s.end());
    for (auto p : s) dfs(p.Y);
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    dep[ROOT] = -1;
    cin >> n;
    for (int i = 0; i<n;i++) {
        string s,t = "";
        cin >> s;
        vector<string> r;
        for (auto c: s) {
            if (c == '\\') {
                r.push_back(t);
                t = "";
            }else
                t += c;
        }
        r.push_back(t);
        insert(r);
    }
    dfs(ROOT);
}

/*
1. 디스크 트리
    - 이문제의 가장 중요한 점은, 하나의 단어를 하나의 인덱스라고 생각해야한다는 점임.
*/