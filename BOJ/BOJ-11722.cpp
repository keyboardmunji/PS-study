#include <bits/stdc++.h>

using namespace std;
int n;
int arr[1001];
int d[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0; i< n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j])
                d[i] = max(d[i], d[j] + 1);
        }
    }
    cout << *max_element(d, d + n);
    return 0;
}

/*
 1. 가장 긴 감소하는 부분 수열
    - N이 적으니 DP로 해결해보자.
*/