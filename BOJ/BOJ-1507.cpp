// Authored by : keyboardmunji
// Created on 2025-06-30.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50000;
int n;
int v[21][21];
bool l[21][21];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0 ;i <n;i++)
        for (int j =0;j<n;j++)
            cin >> v[i][j];
    for (int i =0;i<n;i++) {
        for (int j =0; j<n;j++) {
            bool ch = true;
            for (int k =0; k<n;k++) {

                if (i == k || j == k) continue;
                int s = v[i][k] + v[k][j];
                if (s < v[i][j]) {
                    cout << -1;
                    return 0;
                }
                if (s == v[i][j]) ch = false;
            }
            if (ch) l[i][j] = 1;
        }
    }
    int ans = 0;
    for (int i =0 ;i<n;i++)
        for (int j = i + 1 ; j<n;j++)
            if (l[i][j]) ans += v[i][j];
    cout << ans;
    return 0;
}
/*
1. 궁금한 민호
    - 도시 간 최소거리라, 어떤 도시를 거쳐가든 최소 거리여야함.
*/