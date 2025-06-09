// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
using namespace std;

string a,b;
int alen,blen;
int d[1001][1001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    alen = a.length();
    blen = b.length();
    for (int i = 1; i <= alen;i++) {
        for (int j = 1;j <= blen;j++) {
            if (a[i-1] == b[j-1])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    cout << d[alen][blen] <<'\n';
    int x = alen, y = blen;
    vector<char> v;
    while (x != 0 && y != 0) {
        if (d[x-1][y] == d[x][y])
            x--;
        else if (d[x][y-1] == d[x][y])
            y--;
        else {
            v.push_back(a[x-1]);
            x--;
            y--;
        }
    }
    reverse(v.begin(),v.end());
    for (auto c : v)
        cout << c;
}
/*
1. LCS2
    - LCS1과 다른 점은 되돌아 가는게 추가된듯.
    - 되돌아갈때는 끝에서부터 대각선이랑 1차이 나면 대각선으로 이동하고 리스트에 값 추가.
    - 대각선이랑 1차이가 나지 않으면 i-1,j-1중 같은 값을 가지고 있는곳으로 이동.
*/
