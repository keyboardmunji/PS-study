// Authored by : keyboardmunji
// Created on 2025-06-30.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 62500;
int n,m,u,v,b,k;
vector<vector<bool>> mp(251,vector<bool>(251,false));
vector<vector<int>> val(251,vector<int>(251,MAX));

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i= 0; i<m;i++) {
        cin >> u >> v >> b;
        val[u][v] = 0;
        mp[u][v] = 1;
        if (b == 1) {
            val[v][u] = 0;
            mp[v][u] = 1;
        }
    }
    for (int i = 1; i<=n;i++) val[i][i] = 0;
    for (int i = 1;i <=n;i++) {
        for (int j = 1;j<=n;j++) {
            for (int k = 1;k<=n;k++) {
                val[j][k] = min(val[j][k], val[j][i] + val[i][k]);
                if (mp[i][j] == true && mp[k][i] == true)
                    val[j][k] = min(val[j][k],val[i][j] + val[k][i] + 2);
                if (mp[i][j] == true)
                    val[j][k] = min(val[j][k],val[i][j] + val[i][k] + 1);
                if (mp[k][i] == true)
                    val[j][k] = min(val[j][k],val[j][i] + val[k][i] + 1);
            }
        }
    }
    cin >> k;
    for (int i =0 ;i<k;i++) {
        cin >> u >> v;
        cout << val[u][v] <<'\n';
    }

    return 0;
}
/*
1. 백양로 브레이크
    - 플로이드를 돌리면서 i 번째 노드를 경유할지를 결정함.
    - 근데, 갈 수 없지만, 경로를 뒤집으면 갈 수 있는 세가지 경우가 있음.
        1. j -> i는 없는데, i -> j는 있음. i -> k는 있음.
        2. i -> k는 없는데, k -> i는 있음. j -> i는 있음.
        3. j -> i도 없고, i -> k 도 없는데, i ->j, k ->i 는 있음.
    - 그러면 val배열은 양방향으로 바뀌어야할 최소 개수를 저장하는 배열로 담음. 그러면 입력 값은 전부 0 으로 처리해야함.
    -
*/