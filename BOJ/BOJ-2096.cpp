// Authored by : keyboardmunji
// Created on 2025-06-02.
#include <bits/stdc++.h>
using namespace std;

int n,c,i,j,k,num;
int d1[2][3];
int d2[2][3];
int dx[3] = {-1,0,1};

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (i =0;i < n;i++) {
        for (j = 0; j < 3;j++) {
            cin >> num;
            if (i == 0) {
                d1[i][j] = d2[i][j] = num;
                continue;
            }
            d2[1][j] = 1000001;
            for (k = 0; k<3;k++) {
                c = j + dx[k];
                if (c < 0 || c > 2) continue;
                d1[1][j] = max(d1[1][j],d1[0][c] + num);
                d2[1][j] = min(d2[1][j], d2[0][c] + num);
            }
        }
        if (i != 0) {
            for (int j = 0; j < 3;j ++) {
                d1[0][j] = d1[1][j];
                d2[0][j] = d2[1][j];
            }
        }
    }
    if (n != 1)
        cout << *max_element(d1[1],d1[1]+3) << ' '<< *min_element(d2[1],d2[1]+3);
    else
        cout << *max_element(d1[0],d1[0]+3) << ' '<< *min_element(d2[0],d2[0]+3);
}
/*
1. 내려가기
    - 백트래킹은 시간 복잡도가 오버 될 것 같으니 dp로 풀어봅시다.
    - d[i][j]는 그 장소 까지 도착하는데 최대 값.이라고 하면 될듯.
    - 흠, 메모리 초과가 나서 더 줄여야함. 이전 항 정보만 필요해서, 2,3으로 바꿔도 될듯.
*/
