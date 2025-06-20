// Authored by : keyboardmunji,
// Created on 2025-06-20.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000000;
int n,m,x,y,z;
vector<vector<int>> maap(101,vector<int>(101,MAX));

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0 ;i < m;i++) {
        cin >> x >> y >> z;
        maap[x][y] = min(z,maap[x][y]);
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<= n;j++) {
            for (int k = 1; k<= n; k++) {
                if (maap[i][k] == MAX || maap[j][i] == MAX || j == k) continue;
                maap[j][k] = min(maap[j][k],maap[j][i] + maap[i][k]);
            }
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            if (maap[i][j] == MAX) cout << "0 ";
            else cout << maap[i][j] <<' ';
        }
        cout <<'\n';
    }

}

/*
1. 플로이드
    - 플로이드 알고리즘 연습하기.
*/
