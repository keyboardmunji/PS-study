// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string s;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    vector<string> m(6);
    int l = n / 5;
    vector<vector<bool>> vis(6, vector<bool>(l, false));
    vector<int> ans;
    for (int i = 1; i<= 5;i++) {
        string a;
        for (int j =0;j<l;j++)
            a += s[(i-1)*l + j];
        m[i] = a;
    }
    for (int i = 0; i<l;i++) {
        if (m[1][i] == '#' && vis[1][i] == false) {
            queue<pair<int,int>> q;
            q.push({1,i});
            vis[1][i] = true;
            int cnt = 0;
            while (!q.empty()) {
                auto c = q.front(); q.pop();
                cnt++;
                for (int j =0 ;j <4;j++) {
                    int x1 = c.X + dx[j];
                    int y1 = c.Y + dy[j];
                    if (x1 > 5 || x1<= 0|| y1 < 0 || y1 >= l || m[x1][y1] == '.' || vis[x1][y1] != false) continue;
                    vis[x1][y1] = true;
                    q.push({x1,y1});
                }
            }
            if (cnt == 5) {
                ans.push_back(1);
                continue;
            }else if (cnt == 7)
                ans.push_back(7);
            else if (cnt == 9)
                ans.push_back(4);
            else if (cnt == 13)
                ans.push_back(8);
            else if (cnt == 11) {
                if (m[2][i] == '#')
                    ans.push_back(5);
                else if (m[4][i] == '#')
                    ans.push_back(2);
                else
                    ans.push_back(3);
            }else if (cnt == 12) {
                if (m[3][i+1] == '.')
                    ans.push_back(0);
                else if (m[2][i+2] == '#')
                    ans.push_back(9);
                else
                    ans.push_back(6);
            }
            i += 2;
        }
    }
    for (int i =0; i<ans.size(); i++)
        cout << ans[i];
}
/*
1. 시그널
    -
*/
