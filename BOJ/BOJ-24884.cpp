// Authored by : keyboardmunji
// Created on 2025-08-27.
#include <bits/stdc++.h>

using namespace std;

int n,w,t,k,ans;
int arr[8];

void func2(bool chk, int dis) {
    int box[8] = {0,};
    for (int i = 1; i<= n; i++) {
        if (arr[i] == 0 || (chk == true && dis == i)) continue;
        if (arr[i - 1] > 0 && arr[i + 1] > 0)
            box[i]++;
        else if (arr[i - 1] > 0 || arr[i + 1] > 0)
            box[i] += 2;
        else
            box[i] += 3;
    }
    for (int i = 1; i<= n; i++) {
        arr[i] = max(0, arr[i] - box[i]);
    }
}

void func(int tim, int dis, bool chk) {
    int box[8];
    for (int i = 1; i <= n; i++)
        box[i] = arr[i];
    if (tim == t) {
        func2(chk,dis);
        int cnt = 0;
        for (int i = 1; i<=n; i++)
            if (arr[i] > 0) cnt++;
        if (cnt >= k) ans++;
        for (int i = 1; i <= n; i++)
            arr[i] = box[i];
        return;
    }
    for (int i = -1; i < 2; i++) {
        int c = dis + i;
        if (c < 1 || c > n) continue;
        func2(chk,dis);
        func(tim + 1, c, true);
        for (int j = 1; j<= n; j++)
            arr[j] = box[j];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w >> t >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    func(1, w + 1, false);
    cout << ans;
}
/*
1. 장작 넣기
    - N,T가 충분히 작아서 백트래킹으로 해결할 수 있음.
    - 시간복잡도는 O(3^T)로 충분히 가능함.
*/