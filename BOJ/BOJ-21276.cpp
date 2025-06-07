// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
using namespace std;

int n,m;
string s1,s2;
map<string,set<string>> v;
map<string,set<string>> ch;
map<string,int> indegree;
set<string> people;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0 ;i < n; i++) {
        cin >> s1;
        people.insert(s1);
    }
    cin >> m;
    for (int i= 0;i < m; i++) {
        cin >> s1 >> s2;
        v[s1].insert(s2); // s1이 s2를 가르킴.
        indegree[s2]++;
    }
    queue<string> q;
    for (auto p : people)
        if (indegree[p] == 0) q.push(p);
    while (!q.empty()) {
        string c = q.front(); q.pop();
        int mn = -1;
        string idx;
        for (auto p : v[c]) {
            if (mn == -1 || indegree[p] < mn) {
                mn = indegree[p];
                idx = p;
            }
            if (--indegree[p] == 0) q.push(p);
        }
        if (mn != -1)
            ch[idx].insert(c);
    }
    vector <string> fa;
    for (auto p : people) {
        if (v[p].size() == 0)
            fa.push_back(p);
    }
    cout << fa.size() << '\n';
    for (auto p : fa)
        cout << p << ' ';
    cout <<'\n';
    for (auto p : people) {
        cout << p <<' ' << ch[p].size();
        for (auto t : ch[p])
            cout <<' ' << t;
        cout <<'\n';
    }
}
/*
1. 계보 복원가 호석
    - n명의 사람을 입력 받고, m의 간선을 입력받는다. 간선을 입력받을 때엔, set으로 입력받음.
    - outdegreee가 0인 애가, 시조임.
    - "조상"이란 자신의 부모와 부모의 조상을 가르킴. 그러면 자신의 부모 보다, 자신의 조상이 indegree가 무조건 많아야함.
    - 따라서 outdegree로 뻗은 노드 중, indegree가 가장 작은게 자신의 부모인듯.
*/
