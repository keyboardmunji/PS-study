// Authored by : keyboardmunji,
// Created on 2025-06-13.
#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,k;
vector<pair<int,int>> v[101];
int item[101][101];
vector<int> normal;
int indegree[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i<m;i++) {
        cin >> x >> y >> k;
        v[y].push_back({x,k}); // y를 k개 전달해야한다는 의미.
        indegree[x]++;
    }
    queue<int> q;
    for (int i = 1;i<=n;i++) {
        if (indegree[i] == 0) {
            normal.push_back(i);
            item[i][i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        x = q.front(); q.pop();
        if (x == n) break;
        for (auto c : v[x]) {
            for (auto nor : normal)
                item[c.first][nor] += c.second * item[x][nor];
            if (--indegree[c.first] == 0) q.push(c.first);
        }
    }
    for (auto nor:normal)
        cout << nor <<' '<< item[n][nor] << '\n';
}
/*
1. 장난감 조립
    - 구해야 하는 것 : 기본 부품이 무엇인가 & 기본 부품이 완제품에 몇 개 들어가는가?
    - 기본 부품 -> 1~n - 1중 indegree가 0 인 것. 완제품이 indegree가 0일 수 있나? ㄴㄴ 문제에서는 기본또는 중간이 사용된데
    - 무튼, indegree가 0 인것들을 따로 bool로 true해놓음.
    - 그 다음 위상 정렬하면서 indegree가 0인것들만 넘겨줌. 다음으로 넘겨주면 끝날 듯.
*/
