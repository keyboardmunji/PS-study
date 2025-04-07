// Authored by : keyboardmunji
// Created on 2025-04-07.
#include <bits/stdc++.h>

using namespace std;

int n,k,cnt = 0;
int arr[10001];
int len[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i =0;i<n;i++) cin>> arr[i];

    sort(arr,arr+n);
    for (int i =0; i<n - 1;i++) {
        if (arr[i] == arr[i+1])
            continue;
        len[cnt++] = arr[i+1] - arr[i];
    }
    sort(len,len+cnt,greater<int>());
    int ans = *max_element(arr,arr+n) - *min_element(arr,arr+n);
    cnt = min(cnt,k - 1);
    for (int i = 0 ;i< cnt;i++)
        ans -= len[i];
    cout << ans;
    return 0;
}

/*
 1. 추상화 했을 때, 각선분의 길이를 적절하게 잘라서, 최소의 구간길이를 구하는 것임.
 2. 우선 정렬한 후, 구간길이를 구한다.
 3. 구간 길이도 정렬한 후 최대를 계속 삭제해가면 된다.
 4. 삭제 해간다는 의미는 새로운 시설을 짓는 것과 동일하게 작용한다.
*/