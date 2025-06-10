// Authored by : keyboardmunji,
// Created on 2025-06-11.
#include <bits/stdc++.h>

using namespace std;

int id, d[51],n,sum,cnt;
bool finished[51];
int indegree[51];
int money[51];
int sccID[51];
string a[51];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x) {
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    for (int i = 1; i <= n;i++) {
        if (a[x][i - 1] == 'N') continue;
        if (d[i] == 0) parent = min(parent, dfs(i));
        else if (!finished[i]) parent = min(parent,d[i]);
    }
    if (parent == d[x]) {
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

    cin >> n;
    for (int i = 1 ; i<= n;i++)
        cin >> money[i];
    for (int i = 1;i<=n;i++)
        cin >> a[i];
    for (int i = 1;i<=n;i++)
        if (!finished[i]) dfs(i);
    for (int i =0 ;i < SCC.size();i++)
        for (int j = 0;j < SCC[i].size();j++)
            sccID[SCC[i][j]] = i;

    for (int i = 1;i <=n;i++) {
        for (int j = 1; j<=n ;j++) {
            if (a[i][j-1] == 'N') continue;
            if (sccID[i] != sccID[j]) indegree[sccID[j]]++;
        }
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0 ; i < SCC.size(); i++) {
        int mn = 1001;
        int idx = 0;
        if (indegree[sccID[SCC[i][0]]] == 0) {
            for (int j = 0; j < SCC[i].size();j++) {
                if (mn > money[SCC[i][j]]) {
                    mn = money[SCC[i][j]];
                    idx = SCC[i][j];
                }
            }
        }
        for (int j =0; j<SCC[i].size();j++) {
            if (indegree[sccID[SCC[i][0]]] != 0) {
                pq.push(money[SCC[i][j]]);
                continue;
            }
            if (SCC[i][j] == idx) {
                sum += money[SCC[i][j]];
                cnt++;
            }else
                pq.push(money[SCC[i][j]]);
        }
    }
    while (!pq.empty()) {
        if (pq.top() * cnt < sum) {
            sum += pq.top(); pq.pop();
            cnt++;
        }else
            break;
    }
    cout << fixed << setprecision(12);
    cout << (double) sum / cnt;
}
/*
1. 경찰
    - 타잔 알고리즘으로 SCC 조합을 뽑는다.
    - SCC들을 하나의 노드라고 생각해서 indegree를 뽑는다.
    - indegree가 0인 것들만 SCC조합들 중 가격이 가장 작은 것을 선택한다. 나머지는 priority queue에 넣는다.
    - 가격이 제일 작은 것들의 평균보다 최솟값이 작다면 최솟값을 더해주고 pop한다.
    - queue가 비거나, 평균값이 작아질때까지 반복한다.
*/
