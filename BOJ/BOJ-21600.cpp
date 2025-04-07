#include <bits/stdc++.h>

using namespace std;

int n, mx, exMx;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        if (exMx + 1 <= num)
            exMx += 1;
        else
            exMx = num;
        mx = max(mx, exMx);
    }
    cout << mx;
    return 0;
}
/*
1. 제일 왼쪽부터 수를 입력받는다.
2. 자기 자신의 바로 왼쪽의 최대 계단 길이를 본다.
    if) 제일 처음 -> 1
    if) 최대 계단 길이 + 1 <= 자신의 길이 -> 자신의 최대 계단 길이를 +1로 갱신
    if) 최대 계단 길이 + 1 > 자신의 길이 -> 자신의 최대 계단 길이를 자신의 길이로 갱신.
*/