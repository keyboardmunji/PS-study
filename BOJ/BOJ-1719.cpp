// Authored by : keyboardmunji
// Created on 2025-07-02.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;
int n,m,a,b,c;
vector<vector<int>> v(201,vector<int>(201,MAX));
int nxt[201][201];
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0 ;i<m;i++) {
        cin >> a >> b >> c;
        v[a][b] = min(v[a][b],c);
        v[b][a] = min(v[b][a],c);
        nxt[a][b] = b;
        nxt[b][a] = a;
    }
    for (int i = 1;i<=n;i++) v[i][i] = 0;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            for (int k = 1;k<=n;k++) {
                if (v[j][k] > v[j][i] + v[i][k]) {
                    v[j][k] = v[j][i] + v[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }

    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            if (nxt[i][j] == 0 || nxt[i][j] == MAX )
                cout << "- ";
            else
                cout << nxt[i][j] << " ";
        }
        cout <<'\n';
    }

    return 0;
}
/*
1. 택배
    - nxt 배열 만들기
*/