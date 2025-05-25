// Authored by : keyboardmunji
// Created on 2025-05-25.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
bool vis[1001];
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int cnt = 1;
    for (int i =1;i <=n;i++) cin >> arr[i];
    for (int i =1;i<=n;i++) {
        vis[cnt] = true;
        cout << cnt <<' ';
        int len = arr[cnt];
        bool ch = true;
        for (int i =1 ;i<=n;i++)
            if (vis[i] == false) ch = false;
        if (ch) break;
        for (int j =0; j<abs(len);j++) {
            cnt += len > 0 ? 1:-1;
            if (cnt == 0) cnt = n;
            else if (cnt == n+1) cnt = 1;
            if (vis[cnt]) {
                j--;
                continue;
            }
        }
    }
    return 0;
}
/*

*/