#include <bits/stdc++.h>

using namespace std;
int n,k,mx = 100001;
int coin[101];
int arr[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    fill(arr,arr + 100001, mx);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    for (int i = 0; i < n; i++) {
        arr[coin[i]] = 1;
        for (int j = 1; j <= k; j++)
            if (j > coin[i])
                arr[j] = min(arr[j], arr[j - coin[i]] + 1);
    }
    if (arr[k] == mx)
        cout << -1;
    else
        cout << arr[k];
    return 0;
}

/*
 1. 동전 2
    - 얘는 무조건 그리디라고 생각했는데, 아니네..
    - 완전 배낭 문제 + min으로
    - 중복 있는 코인 있어도 걸러질듯.
*/