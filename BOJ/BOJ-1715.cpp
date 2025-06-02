// Authored by : keyboardmunji
// Created on 2025-06-03.
#include <bits/stdc++.h>
using namespace std;

int n,x;
long long sum = 0;
priority_queue<long long,vector<long long>,greater<>> q;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0;i<n;i++) {
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1) {
        long long num = q.top(); q.pop();
        num += q.top(); q.pop();
        sum += num;
        q.push(num);
    }
    cout << sum;
}
/*
1. 카드 정렬하기
    - 조심할 점은 int overflow 정도
    - 그렇다고 생각했는데, 4개의 경우에 2 , 2로 나누어서 비교한 후에 그다은ㅁ 합칠 수 도 있었음.
    - 즉, 합치고 나서 다시 최소 2개를 찾아서 합쳐야함.
    - 우선순위 q나 쓰자.
*/
