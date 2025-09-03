#include <bits/stdc++.h>

using namespace std;
int n;
int arr[1001];
vector<int> d1,d2;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    d1.resize(n);
    d2.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    d1[0] = d2[0] = 1;
    for(int i = 1; i < n; i++){
        d1[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                d1[i] = max(d1[i],d1[j] + 1);
            }
        }
    }
    reverse(arr, arr + n);
    for (int i = 1; i < n; i++) {
        d2[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                d2[i] = max(d2[i], d2[j] + 1);
            }
        }
    }
    reverse(d2.begin(),d2.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans,d1[i] + d2[i] - 1);
    cout << ans;
    return 0;
}

/*
 1. 가장 긴 바이토닉 부분 수열
    - 현재 기준 dp로 부분수열을 구함 -> 그러면 d[i]는 현재 자기를 포함한 가장 긴 부분 수열이 생길 꺼임.
    - 그 다음, 반대로 돌리고 동일하게 진행함. -> 이결과를 reverse 해서, 그 2개의 합 - 1이 가장 큰 것이 정답임.
*/