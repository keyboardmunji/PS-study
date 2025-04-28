// Authored by : keyboardmunji
// Created on 2025-04-28.
#include <bits/stdc++.h>
using namespace std;

int t = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (++t) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        unordered_map<string,int> m;
        vector<int> v(n+1,0);
        vector<bool> vis(n+1,false);
        int cnt=0,ans = 0;
        for (int i =0;i<n;i++) {
            string a,b;
            cin >> a >> b;
            if (m[a] == 0)
                m[a] = ++cnt;
            if (m[b] == 0)
                m[b] = ++cnt;
            v[m[a]] = m[b];
        }
        for (int i =1;i<=n;i++) {
            if (vis[i] == true) continue;
            ans++;
            int j = v[i];
            while (vis[j] == false) {
                vis[j] = true;
                j = v[j];
            }
        }
        cout <<t << ' '<< ans <<'\n';
    }

    return 0;
}
/*
1. 해시 자료구조를 이용해서 그 값이 이전에 나왔는지 확인할 것임.
2. ㅎㅁ,, 각각이 존재했는지 확인하고, bfs돌리자.
*/