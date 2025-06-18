// Authored by : keyboardmunji,
// Created on 2025-06-19.
#include <bits/stdc++.h>

using namespace std;
int n,m,a,b,c;
int p[2][1001];
vector<tuple<int,int,int>> g1;
vector<tuple<int,int,int>> g2;

int find(int x,int i) {
    if (p[i][x] < 0)
        return x;
    return p[i][x] = find(p[i][x],i);
}

bool uni(int u,int v,int i) {
    u = find(u,i);
    v = find(v,i);
    if (u == v)
        return false;
    if (p[i][u] > p[i][v])
        swap(u,v);
    if (p[i][u] == p[i][v])
        p[i][u]--;
    p[i][v] = u;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(p[0], p[0] + 1001, -1);
    fill(p[1], p[1] + 1001, -1);
    cin >> n >> m;
    for (int i =0;i <= m;i++) {
        cin >> a >> b >> c;
        g1.push_back({c,a,b});
        g2.push_back({c,a,b});
    }
    sort(g1.begin(), g1.end(),greater<tuple<int,int,int>>());
    sort(g2.begin(), g2.end());
    int cnt1 = 0,sum1 = 0,sum2 = 0,cnt2 = 0;
    for (int i = 0;i<= m;i++) {
        tie(a,b,c) = g1[i];
        if (!uni(b,c,0)) continue;
        if (cnt1 == n) break;
        if (a == 0) {
            cnt2++;
        }
    }
    sum1 = cnt2 * cnt2;
    cnt1 = cnt2 = 0;
    for (int i = 0;i<= m;i++) {
        tie(a,b,c) = g2[i];
        if (!uni(b,c,1)) continue;
        if (cnt1 == n) break;
        if (a == 0) cnt2++;

    }
    sum2 = cnt2 * cnt2;
    cout << sum2 - sum1;
}
/*
1. 학교 탐방하기
    - 실선을 가중치 1로 두고 점선을 가중치 2로 둬서 MST를 돌린 결과와 뒤집은 결과를 비교하면 될듯.
*/
