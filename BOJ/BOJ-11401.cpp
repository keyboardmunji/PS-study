// Authored by : keyboardmunji
// Created on 2025-05-31.
#include <bits/stdc++.h>
using namespace std;

int n,k;
long long sum1 = 1,sum2 = 1, m = 1000000007;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    k = min(k,n-k);
    for (int i =1; i <=k;i++) {
        sum1 = sum1 * (n-i+1) % m;
        sum2 = sum2 *  i % m;
    }
    long long e = m-2;
    long long sum3 = 1;
    while (e > 0) {
        if (e & 1) sum3 = sum3 * sum2 % m;
        sum2 = sum2 *sum2 % m;
        e >>= 1;
    }
    cout << sum1 * sum3 %m;
}
/*
1. 아 mod할때 나누면 안된데, 심지어 사이즈도 커서 모듈러 역원을 할 줄 알아야함.
2. 모듈러 역원을 구하는 방법은 페르마의 소정리로 구할 수 있움. m이 소수일 떄.
*/