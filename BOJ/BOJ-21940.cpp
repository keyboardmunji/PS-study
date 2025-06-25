// Authored by : keyboardmunji,
// Created on 2025-06-25.
#include <bits/stdc++.h>

using namespace std;
const int MAX = 10000000;
int n,m,a,b,c;
vector<vector<int>> val(201,vector<int>(201,MAX));
vector<int> fr;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0 ; i<m;i++) {
        cin >> a >> b>> c;
        val[a][b] = min(val[a][b],c);
    }

    for (int i = 1; i<=n;i++) val[i][i] = 0;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++)
            for (int k = 1; k<=n;k++)
                val[j][k] = min(val[j][k], val[j][i] + val[i][k]);

    cin >> a;
    for (int i = 0;i<a;i++) {
        cin >> b;
        fr.push_back(b);
    }
    vector<int> ans;
    int mn = MAX,mx;
    for (int i = 1; i<= n;i++) {
        bool ch = false;
        mx = 0;
        for (int j = 0;j<a;j++) {
            if (val[i][fr[j]] == MAX || val[fr[j]][i] == MAX) {
                ch = true;
                break;
            }
            mx = max(mx ,val[i][fr[j]] + val[fr[j]][i]);
        }
        if (ch) continue;
        if (mn > mx) {
            mn = mx;
            ans.clear();
            ans.push_back(i);
        }else if (mn == mx)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for (auto c : ans)
        cout << c <<' ';
}
/*
문제 : 가운데서 만나기
    - 친구들까지 있어서 플로이드로 처리할 예정.
*/
