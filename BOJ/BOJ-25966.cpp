// Authored by : keyboardmunji
// Created on 2025-04-11.
#include <bits/stdc++.h>
using namespace std;

int mp[3001][3001];
int idx[3001];
int n,m,q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for (int i =0;i<n;i++) {
        idx[i] = i;
        for (int j =0;j<m;j++)
            cin >> mp[i][j];
    }
    for (int i =0;i<q;i++) {
        int num;
        cin >> num;
        if (num == 0) {
            int a,b,c;
            cin >> a >> b>> c;
            mp[idx[a]][b] = c;
        }else {
            int a,b;
            cin >> a >> b;
            swap(idx[a],idx[b]);
        }
    }

    for (int i =0;i<n;i++) {
        int idx2 = idx[i];
        for (int j =0;j<m;j++) {
            cout << mp[idx2][j] <<' ';
        }
        cout <<'\n';
    }
    return 0;
}



