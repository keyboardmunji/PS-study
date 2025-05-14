// Authored by : keyboardmunji
// Created on 2025-05-14.
#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[123457]; // 방문 체크
vector<tuple<char,int,int>> arr;
vector<vector<int>> v;
long long dfs(int r) {
    long long sum = 0;
    if (get<0>(arr[r]) == 'W')
        sum -= get<1>(arr[r]);
    else
        sum = get<1>(arr[r]);
    vis[r] = true;
    int len = v[r].size();
    for (int i = 0; i< len;i++) {
        if (vis[v[r][i]] == true) continue;
        sum += dfs(v[r][i]);
    }
    return sum >= 0 ? sum : 0;
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n+1);
    v.resize(n+1);

    for (int i =2;i<=n;i++) {
        cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
        v[i].push_back(get<2>(arr[i]));
        v[get<2>(arr[i])].push_back(i);
    }
    cout << dfs(1);

    return 0;
}
/*
1. BFS 돌리면서 자기 앞에 길에 늑대 수가 더 많은지 확인
2. 양을 먹으면 vis[c]가 줄어드는 듯. 최대 한마리라길래.
3. 최대 한마리를 적용시키리면 bfs가 아닌 dfs를 돌려야함. -> bfs를 돌리면 제대로 적용이 안됨.
*/