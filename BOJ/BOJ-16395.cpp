#include <bits/stdc++.h>

using namespace std;
int n,m;
long long d[31][31];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    d[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        d[i][i] = d[i][1] = 1;
        for (int j = 2; j <= i - 1; j++)
            d[i][j] = d[i-1][j] + d[i-1][j-1];
    }
    cin >> n >> m;
    cout << d[n][m];
    return 0;
}

/*
 1. 파스칼 삼각형
    - 삼각형을 2차원으로 받아야 입력에서 출력하기 편함.
*/