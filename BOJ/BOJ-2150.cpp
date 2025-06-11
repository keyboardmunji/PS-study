// Authored by : keyboardmunji,
// Created on 2025-06-11.
#include <bits/stdc++.h>

using namespace std;

int id, d[10001],v,e,n1,n2;
bool finished[10001];
vector<int> a[10001];
stack <int> s;
vector<vector<int>> SCC;

int dfs(int x) {
    d[x] = ++id;
    s.push(x);
    int parent = d[x];
    for (auto c : a[x]) {
        if (d[c] == 0) parent = min(parent,dfs(c));
        else if (!finished[c]) parent = min(parent,d[c]);
    }
    if(parent == d[x]) {
        vector<int> scc;
        while (1) {
            int t = s.top(); s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i<e;i++) {
        cin >> n1 >> n2;
        a[n1].push_back(n2);
    }
    for (int i =1;i<=v;i++)
        if (!finished[i]) dfs(i);
    cout << SCC.size() << '\n';
    for (int i = 0;i<SCC.size();i++) sort(SCC[i].begin(),SCC[i].end());
    sort(SCC.begin(),SCC.end());
    for (int i = 0; i< SCC.size();i++) {
        for (int j = 0; j<SCC[i].size();j++) cout << SCC[i][j] << " ";
        cout << "-1\n";
    }
}
/*
1. Strongly Connected Component
    - SCC구하기.
*/
