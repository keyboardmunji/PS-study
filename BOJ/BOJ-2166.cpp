// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
long long sum1,sum2;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<pair<long long,long long>> p(n + 1);
    for (int i =0 ;i <n;i++) cin >> p[i].X >> p[i].Y;
    p[n].X = p[0].X;
    p[n].Y = p[0].Y;
    for (int i =0; i< n;i++) {
        sum1 += p[i].X*p[i+1].Y;
        sum2 -= p[i+1].X *p[i].Y;
    }
    cout << fixed << setprecision(1);
    cout << abs(sum1 + sum2) / 2.0;
}
/*
1. 다각형의 면적
    - 문제의 핵심은 다각형을 이루는 순서대로 점의 좌표가 주어진다는 것.
    - 첫번째 정점을 st, ed 를 st + 2라고 잡자. 그리고 첫번째 정점을 끝에 하나 더 넣자.
    - st ~ st+2 점점들의 삼각형 넓이를 구함.
    - s= 0 부터 시작하며 0번째 값이 n에 담겨있음.
    - st + 2 = n이 되었을 때의 계산을 마지막으로 해서 답을 구하면 됨.
    - 흠.. 이방식은 안쪽으로 들어가 있는 다각형에 대해서 제대로 구하지 못함.
    - 찾아보니 신발끈 공식은 삼각형만 그런게 아니라, 확장이 n각형에 대해서 그렇게 접근가능함.

*/
