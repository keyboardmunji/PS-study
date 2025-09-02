#include <bits/stdc++.h>

using namespace std;
int d[31];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n%2) {
        cout << 0;
        return 0;
    }
    d[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        for (int j = 2; j < i - 2; j += 2)
            d[i] += d[j] * 2;
        d[i] += d[i - 2] * 3;
        d[i] += 2;
    }
    cout << d[n];
    return 0;
}

/*
 1. 타일 채우기.
    - n이 홀수 일때 경우의 수는 무조건 0임. -> n*2는 짝수이기 때문.
    - 따라서 n이 짝수 일때 가능.
    - n = 2 -> 총 3가지의 경우의 수가 있음.
    - n = 4 -> 3 * 3 + 2 의 경우의 수 가 있음.
    - n = 6 -> 2 + d[4] * 3 + d[2] * 2
    - n = 8 -> 2 + d[6] * 3 + d[4] * 2 + d[2] * 2 로 됨.
*/