// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin >> n >> m;
        for (int i =0 ;i<m;i++)
            cin >> a >> b;
        cout << n- 1<<'\n';
    }
}
/*
1. 상근이의 여행
    - 간선의 개수 -> 비행기의 종류
    - 그렇다면 가장 적은 종류 -> n - 1일 수 밖에 없음.
*/
