// Authored by : keyboardmunji
// Created on 2025-07-08.
#include <bits/stdc++.h>
using namespace std;

int t;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        string a,w,s;
        vector<int> ans;
        cin >> a >> w >> s;
        unordered_map<char,int> mp;
        for (int i =0; i<a.size();i++)
            mp[a[i]] = i;
        if (w.size() == 1) {
            vector<int> ch(a.size(),0);
            for (int i =0 ;i<s.size();i++)
                ch[mp[s[i]]]++;
            for (int i =0;i<ch.size();i++)
                if (ch[i] == 1)
                    ans.push_back(mp[w[0]] > i ? a.size() - mp[w[0]] + i : i - mp[w[0]]);
            sort(ans.begin(), ans.end());
        }else {
            vector<int> v1,v2;
            for (int i =0 ; i < w.size() - 1;i++)
                v1.push_back(mp[w[i]] > mp[w[i + 1]] ? a.size() - mp[w[i]] + mp[w[i + 1]] : mp[w[i + 1]] - mp[w[i]]);
            for (int i = 0; i < s.size() - 1;i++)
                v2.push_back(mp[s[i]] > mp[s[i + 1]] ? a.size() - mp[s[i]] + mp[s[i + 1]] : mp[s[i + 1]] - mp[s[i]]);
            vector<int> f(v1.size());
            int j = 0;
            for (int i = 1;i<v1.size();i++) {
                while (j > 0 && v1[j] != v1[i]) j = f[j-1];
                if (v1[j] == v1[i]) f[i] = ++j;
            }
            j = 0;
            vector<int> ch(a.size(),0);
            for (int i = 0;i<v2.size();i++) {
                while (j > 0 && v1[j] != v2[i]) j = f[j-1];
                if (v1[j] == v2[i]) j++;
                if (j == v1.size()) {
                    int num = (mp[w[j - 1]] > mp[s[i]] ? a.size() - mp[w[j - 1]] + mp[s[i]] : mp[s[i]] - mp[w[j - 1]]);
                    ch[num]++;
                    j = f[j-1];
                }
            }
            for (int i = 0;i<ch.size();i++)
                if (ch[i] == 1) ans.push_back(i);
        }
        if (ans.size() == 0)
            cout << "no solution\n";
        else if (ans.size() == 1)
            cout << "unique: " << ans[0] << '\n';
        else {
            cout << "ambiguous: ";
            for (auto c : ans)
                cout << c <<' ';
            cout <<'\n';
        }
    }

    return 0;
}
/*
1. 시저 암호
    - 이 문제에서 중요하다고 생각하는 것
        1. 주어진 순서대로 정수로 매핑하는 것.
        2. 매핑한 결과값의 차이를 따로 구하고, 그 값을 KMP돌리는 것
    - 즉, 두 수의 차이의 순서가 동일하면 시프트를 했을 때 그 문자열이 가능하다고 보는 것임.
    - 단 W가 1일때 예외처리를 해줘야함. 두수의 차가 불가능해서
*/