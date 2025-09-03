#include <bits/stdc++.h>

using namespace std;
string s;
int d[5001];

int c2i(char c) {
    return c - '0';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int s_len = s.length();
    if (s[0] != '0')
        d[0] = 1; // 초기값
    else {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < s_len; i++) {
        if (s[i] != '0')
            d[i] = d[i-1];
        if (s[i-1] != '0' && c2i(s[i-1]) * 10 + c2i(s[i]) <= 26)
            d[i] += (i > 1 ? d[i-2] : 1);
        if (d[i] == 0) {
            cout << 0;
            return 0;
        }
        d[i] = d[i] % 1000000;
    }
    cout << d[s_len - 1];
    return 0;
}

/*
 1. 암호코드
    - 얘는 추상화 때리면 (1*1, 1*2) 이 2개의 직사각형으로 1*n을 채우는 경우의 수를 세는 문제임.
    - d[i] = i번째 까지 가능한 경우의 수
      d[i] = d[i-1] + d[i-2] (if, d[i-2]는 조건 만족)
    - 근데, 조건이 1*2에서는 26이하가 되어야함.
    - 아, 0도 있었누.
*/