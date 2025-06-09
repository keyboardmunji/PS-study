// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
using namespace std;

bool a[10][10]; // 가로
bool b[10][10]; // 세로
bool c[4][4][10]; // 3x3
int maap[10][10];
string s;
bool ch = false;

void func1(int x,int y){
    if (ch)
        return;
    if (y == 9) {
        if (x == 8) {
            ch = true;
            for (int i = 0;i<9;i++) {
                for (int j =0;j<9;j++) cout << maap[i][j];
                cout <<'\n';
            }
            return;
        }
        func1(x+1,0);
    }else {
        if (maap[x][y] != 0) {
            func1(x, y + 1);
        }else {
            for (int i = 1;i<=9;i++) {
                if (!a[x][i] && !b[y][i] && !c[x/3][y/3][i]) {
                    maap[x][y] = i;
                    a[x][i] = true;
                    b[y][i] = true;
                    c[x/3][y/3][i] = true;
                    func1(x,y+1);
                    maap[x][y] = 0;
                    a[x][i] = false;
                    b[y][i] = false;
                    c[x/3][y/3][i] = false;
                }
            }
        }
    }
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    for (int i =0; i<9;i++) {
        cin >> s;
        for (int j =0 ;j <9;j++) {
            int t = s[j] - '0';
            maap[i][j] = t;
            if (t != 0) {
                a[i][t] = true;
                b[j][t] = true;
                c[i/3][j/3][t] = true;
            }
        }
    }
    func1(0,0);
}
/*
1. 스도쿠
    - 각 행, 각 열, 3x3크기의 보드에 있는 수들이 있는지 확인하는 bool 배열 3개를 만든다
    - 문제 조건에서 12095번에 있는 소스로 풀 수 있는 입력만 주어진다는데, 12095번 소스는
      모든 경우를 한번에 백트래킹으로 돌리는거라 나도 그렇게 짰음.
*/
//
// Created by ASUS on 25. 6. 9.
//
