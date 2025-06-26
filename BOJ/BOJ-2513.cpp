// Authored by : keyboardmunji,
// Created on 2025-06-26.
#include <bits/stdc++.h>

using namespace std;
int n,k,s,a,b;
vector<pair<int,int>> v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> s;
    for (int i = 0; i<n;i++) {
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int i = 0,j = 0,sum = 0,idx = v[i].first;// j : 현재 탑승 인원
    while (i < n && v[i].first < s) {
        if (v[i].second > k - j) {
            v[i].second -= k - j;
            j = k;
        }else{
            j += v[i].second;
            v[i].second = 0;
        }
        if (v[i].second == 0) i++;
        if (j == k) {
            sum += (s - idx) * 2;
            j = 0;
            idx = v[i].first;
        }
    }
    sum += (j != 0 ? (s - idx)  * 2 : 0);
    i = n - 1;
    j = 0;
    idx = v[n-1].first;
    while (i >= 0 && v[i].first > s) {
        if (v[i].second > k - j) {
            v[i].second -= k - j;
            j = k;
        }else{
            j += v[i].second;
            v[i].second = 0;
        }
        if (v[i].second == 0) i--;
        if (j == k) {
            sum += (idx - s) * 2;
            j = 0;
            idx = v[i].first;
        }
    }
    sum += (j != 0 ? (idx - s)  * 2 : 0);
    cout << sum;
}
/*
문제 : 통학버스
    - 무조건 학교 기준 멀리 있는 집부터 돌아야함. 그 다음, 학교 왼쪽과 오른쪽을 따로 처리하면 됨.
*/
