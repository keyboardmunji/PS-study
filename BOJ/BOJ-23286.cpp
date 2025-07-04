// Authored by : keyboardmunji
// Created on 2025-07-04.
#include <bits/stdc++.h>
using namespace std;

const int HMAX = 1000001;
int n,m,t,u,v,h;
vector<vector<int>> d(301,vector<int>(301,HMAX));

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;
    for (int i =0 ; i< m;i++) {
        cin >> u >> v >> h;
        d[u][v] = min(d[u][v], h);
    }

    for (int i = 1;i<=n;i++) d[i][i] = 0;

    for (int i = 1; i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            for (int k = 1;k<=n;k++) {
                int l = max(d[j][i], d[i][k]);
                if (d[j][k] > l) d[j][k] = l;
            }
        }
    }

    while (t--) {
        cin >> u >> v;
        if (d[u][v] == HMAX)
            cout << -1;
        else
            cout << d[u][v];
        cout <<'\n';
    }

    return 0;
}
/*
1. 허들 넘기
    - 일단 4만번의 오고 가는걸 확인할 수 는 없을듯.
    - 그러면 허들 높이 기준으로 가장 낮은걸 저장하는 플로이드 알고리즘을 만들어보자.
*/