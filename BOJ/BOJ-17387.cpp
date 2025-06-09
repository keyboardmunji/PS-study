// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
    long long t = (p2.X - p1.X)*(p3.Y-p1.Y) - (p2.Y - p1.Y) *(p3.X - p1.X);
    if (t > 0)
        return 1;
    else if (t==0)
        return 0;
    else
        return -1;
}

pair<long long,long long> a,b,c,d;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y;

    int ab = ccw(a,b,c) * ccw(a,b,d);
    int cd = ccw(c,d,a) * ccw(c,d,b);

    if (ab == 0 && cd == 0) {
        if (a > b) swap(a,b);
        if (c > d) swap(c,d);
        cout << !(b < c || d < a);
        return 0;
    }
    cout << (ab <= 0 && cd <= 0);
}
/*
1. 선분교차 2
    - CCW를 이용함.
    - CCW에서 각 선분당 CCW의 곱이 음수여야 함.
    - 근데, 0 일때 주의 해야함. 0인게 2개 있는 경우 겹치는 곳이 있는지.
*/
