// Authored by : keyboardmunji
// Created on 2025-08-29.
#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int p[11];
long long mx = 0;

void func1(long long day,long long p_cnt, long long my, long long pp) {
    if (day == n) {
        my += (p_cnt) * p[n];
        mx = max(mx,my);
        return;
    }
    func1(day + 1, p_cnt, my, pp);
    if (p_cnt >= 0) {
        my += (p_cnt) * p[day];
        p_cnt = 0;
        func1(day + 1, p_cnt, my, pp);
    }
    if (pp > 0) {
        if (my - pp > 0) {
            my -= pp;
            pp = 0;
        }
    }
    if (pp == 0) {
        if (my * (k + 1) >= p[day]) {
            pp = my * k;
            p_cnt = (my * (k + 1)) / p[day];
            my = (my * (k + 1)) % p[day];
            func1(day + 1, p_cnt, my, pp);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i<= n; i++) cin >> p[i];
    mx = m;
    func1(1, 0, m, 0);
    cout << mx;
}
/*
1. 주식
    - 다음 날이 크면 무조건 이득이고, 다음날이 작으면 무조건 손해임. -> 이건 2일만 봤을 때 필연적
    - x원을 가지고 있고, y1원이 오늘 가격, y2가 내일 가격이라 할때
    -> (x*(k+1) / y1) * y2를 벌 수 있음. 즉, y2 > y1이면, 자신의 자본은 항상 증가하게 됨. 미래에 증가할 걸 알면, 그때 투자하면 됨.
    -> 묵히는건, 자신의 미래가 암담할 때 묵히는거임.
    -> 단순히 2일만 바라보고 go하면 최댓값을 구할 수 없음.
    -> 따라서 백트래킹이 좋을듯. n도 적으니.
    -> 이렇게 하면 될듯.
*/