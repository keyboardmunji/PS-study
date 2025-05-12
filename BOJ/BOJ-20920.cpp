// Authored by : keyboardmunji
// Created on 2025-05-12.
#include <bits/stdc++.h>
using namespace std;

vector<tuple <int,int,string>> arr;
unordered_map<string,int> se;
const int MAX = 100000;
int n,m;
string s;

int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0;i<n;i++) {
        cin >> s;
        se[s]++;
    }
    for (auto &it : se) {
        if (it.first.length() < m) continue;
        arr.push_back({MAX - it.second,10 - it.first.length(),it.first});
    }
    sort(arr.begin(),arr.end());
    int len = arr.size();
    for (int i = 0;i<len;i++)
        cout << get<2>(arr[i]) <<'\n';

    return 0;
}
/*
1.
*/