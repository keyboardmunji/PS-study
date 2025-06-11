// Authored by : keyboardmunji,
// Created on 2025-06-12.
#include <bits/stdc++.h>

using namespace std;
int n,m,x,y;
vector<int> v[100001];
int val[100001];

void dfs(int node) {
    for (auto c : v[node]) {
        val[c] += val[node];
        dfs(c);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> x;
        if (i == 1) continue;
        v[x].push_back(i);
    }

    for (int i = 0; i<m;i++) {
        cin >> x >> y;
        val[x] += y;
    }
    dfs(1);
    for (int i = 1;i<=n;i++) cout << val[i] <<' ';
}
/*
1. 회사 문화1
    - 각 노드는 자기 자식들의 노드들을 저장한다.
    - 그 다음 dfs를 돌리면서 자기 아들들의 값을 증가시키면 끝난다.
    - 흠.. 시간 초과가 나는군. 그러면 x,y를 받고 val에 추가함.
    - 그 다음 제일 위에서 부터, 자식 한테 자신의 값을 주는걸 하면될듯.
    - 이러면 한번의 dfs로 가능함.
*/
