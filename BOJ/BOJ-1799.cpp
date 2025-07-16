// Authored by : keyboardmunji
// Created on 2025-07-16.
#include <bits/stdc++.h>
using namespace std;

int n,x;
vector<pair<int,int>> v[2][20];
bool used[2][20];
int mx[2];
void func1(int a,int m,int ch) {
    if (a == 2 * n - 1) {
        mx[ch] = max(mx[ch],m);
        return ;
    }
    for (auto p : v[ch][a]) {
        int x,y;
        tie(x,y) = p;
        if (used[ch][n + x - y - 1]) continue;
        used[ch][n + x - y- 1] = true;
        func1(a + 1, m + 1, ch);
        used[ch][n + x - y - 1] = false;
    }
    func1(a+1,m,ch);
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i<n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> x;
            if (x)
                v[(i+j+1)%2][i+j].push_back({i,j});
        }
    }
    func1(0,0,1);
    func1(0,0,0);
    cout << mx[0] + mx[1];
}

/*
1. 비숍
    - 일단, 대각선만 고려하는걸로 시간복잡도를 대폭 줄일 수 있음.
    - 다음으로 비숍의 특성상, 검은칸은 검은칸만, 흰칸은 흰칸만 이동가능함.
    - 따라서 그렇게 2가지로 나누어서 시간복잡도를 더 줄일 수 있음.
    - 우선 한쪽 대각선이 가능한 곳들만 입력받는다. 그 다음 백트래킹을 진행한다.
    - 백트래킹을 진행하면서, 내가 하려던 곳을 사용할 수 있는지 없는지 체크하고 넘김.
    - 그렇게 진행하면 될듯.
*/