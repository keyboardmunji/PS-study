// Authored by : keyboardmunji
// Created on 2025-07-17.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,t;
const int ROOT = 1;
int unused = 2;
const int MX = 1000*15 + 5;
unordered_map<string, int> used[MX];
int depth[MX];
string name[MX];

void insert(vector<string>& s) {
    int cur = ROOT;
    for (auto c : s) {
        int idx = used[cur][c];
        if (idx == 0) {
            idx = used[cur][c] = unused++;
        }
        depth[idx] = depth[cur] + 2;
        name[idx] = c;
        cur = idx;
    }
}

void dfs(int v) {
    if (v != ROOT) {
        for (int i = 0; i < depth[v];i++) cout <<'-';
        cout << name[v] <<'\n';
    }
    vector<pair<string,int>> s(used[v].begin(), used[v].end());
    sort(s.begin(), s.end());
    for (auto p: s) dfs(p.Y);
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    depth[ROOT] = -2;
    cin >> n;
    for (int i =0 ; i< n; i++) {
        cin >> t;
        vector<string> r;
        for (int j = 0; j<t;j++) {
            string s;
            cin >> s;
            r.push_back(s);
        }
        insert(r);
    }
    dfs(ROOT);
}

/*
1. 개미굴
    - 문자열을 하나의 문자라고 생각하고 접근하는 트라이 연습.
*/