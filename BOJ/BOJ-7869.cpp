// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>

using namespace std;
const double pi = 3.14159265358979323846;
long double a1,b1,a2,b2,r1,r2,l;

int main(void) {
    cin >> a1 >> b1 >> r1 >>  a2 >> b2 >> r2;
    l = sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
    if (l >= r1 + r2)
        printf("%.3Lf",0.000L);
    else if (l <= fabsl(r1-r2)) {
        printf("%.3Lf",min(r1,r2)* min(r1,r2) * pi);
    }else {
        long double s1 = (l + r1 + r2) / 2;
        long double s = r1*r1*acos((r1*r1+l*l-r2*r2)/(2*l*r1)) + r2*r2*acos((r2*r2+l*l-r1*r1)/(2*l*r2)) - 2 * sqrt(s1*(s1-r1)*(s1-r2)*(s1-l));
        printf("%.3Lf",s);
    }
}
/*
1. 두 원
    - 두 중심점 사이의 거리와, 반지름 제곱의 합의 관계에 따라 너비가 달라짐. 일단 r1 < r2라 하자.
    - 1. 너비가 0인경우 -> 거리 >= r1^2 + r2^2
    - 2. 너비가 r2^2인경우 -> 거리 <= r1^2 - r2^2인 경우
    - 3. 나머지는 모두 교점이 2개인 것들
*/
