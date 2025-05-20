// Authored by : keyboardmunji
// Created on 2025-05-20.
#include <bits/stdc++.h>
using namespace std;

char v[25][25];
char s[2] = {'#','.'};
int n,m;
int u,l,r,d; // up,left,right,down

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> u >> l >> r >> d;

    for (int i =0; i< n + u + d;i++) {
        for (int j =0;j<m+l+r;j++) {
            v[i][j] = s[(i+j) % 2];
        }
    }
    for (int i = u;i<u + n;i++)
        for (int j = l;j<l+m;j++)
            cin >> v[i][j];
    for (int i =0; i< n + u + d;i++) {
        for (int j =0;j<m+l+r;j++) {
            cout << v[i][j];
        }
        cout <<'\n';
    }
    return 0;
}
/*
1.받을 때 부터 그 자리에 받고 공백이면 자리 에 따라 정하기.
*/