// Authored by : keyboardmunji,
// Created on 2025-06-20.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000000;
int n,m,x,y,z;
vector<vector<int>> maap(101,vector<int>(101,MAX));
int nxt[101][101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0 ;i < m;i++) {
        cin >> x >> y >> z;
        maap[x][y] = min(maap[x][y],z);
        nxt[x][y] = y;
    }
    for (int i = 1;i<=n;i++) maap[i][i] = 0;

    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<= n;j++) {
            for (int k = 1; k<= n; k++) {
                if (maap[j][k] > maap[j][i] + maap[i][k]) {
                    maap[j][k] = maap[j][i] + maap[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            if (maap[i][j] == MAX || i == j) cout << "0 ";
            else cout << maap[i][j] <<' ';
        }
        cout <<'\n';
    }
    for (int i = 1; i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            if (maap[i][j] == MAX || i == j) {
                cout << "0\n";
                continue;
            }
            x = i;
            vector<int> ans;
            while (x != j) {
                ans.push_back(x);
                x = nxt[x][j];
            }
            ans.push_back(j);
            cout << ans.size() <<' ';
            for (auto c : ans) cout << c <<' ';
            cout <<'\n';
        }
    }
}

/*
1. 플로이드 2
    - 플로이드 알고리즘 연습하기.
*/
