// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>

using namespace std;
int n,m,x,y;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    bool ch = false;
    vector<pair<int,int>> v;
    for (int i =0 ;i< m;i++) {
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    int st = 0, ed = 0;
    for (int i = 0; i< m; i++) {
        if (ed < v[i].first) {
            n -= ed - st;
            st = v[i].first;
            ed = v[i].second;
        }else {
            if (ed < v[i].second)
                ed = v[i].second;
        }
    }
    n -= ed - st;
    cout << n;
}
/*
1. 동방 프로젝트 (Large)
    - sort해서 st, ed만 잘 구분해줘서 해결하면 되는거 아닌가?
*/
