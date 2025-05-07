// Authored by : keyboardmunji
// Created on 2025-05-07.
#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string,string> a; // 키 : 맴버 , 값 : 팀이름
unordered_map<string,vector<string>> b; // 키 : 팀이름, 값 : 각 맴버

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i<n;i++) {
        string s;
        int num;
        cin >> s >> num;
        for (int j = 0;j<num;j++) {
            string name;
            cin >> name;
            b[s].push_back(name);
            a[name] = s;
        }
    }

    for (int i =0;i<m;i++) {
        string name;
        int q;
        cin >> name >> q;
        if (q)
            cout << a[name] <<'\n';
        else {
            sort(b[name].begin(),b[name].end());
            int len = b[name].size();
            for (int j = 0;j<len;j++)
                cout << b[name][j] <<'\n';
        }
    }

    return 0;
}
/*
1. 해시 이용
*/