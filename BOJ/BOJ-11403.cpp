// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[101][101];


int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i<= n;i++)
        for (int j = 1;j<=n;j++) cin >> arr[i][j];

    for (int i = 1;i<=n;i++) {
        queue<int> q;
        vector<bool> vis(n + 1);
        q.push(i);
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (int j = 1;j<=n;j++) {
                if (arr[c][j] == 0 || vis[j] == true) continue;
                q.push(j);
                vis[j] = true;
            }
        }
        for (int j = 1;j<=n;j++)
            arr[i][j] = vis[j];
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++)
            cout << arr[i][j] <<' ';
        cout << '\n';
    }

}
/*
1. 경로 찾기.
    - 당장 생각나는 건, 모든행에 대해 BFS를 돌려서 한 행씩 채워 나가는것.
    - 시간 복잡도가 O(N^3)이라 가능할 듯.
*/
