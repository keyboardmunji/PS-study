// Authored by : keyboardmunji
// Created on 2025-06-03.
#include <bits/stdc++.h>
using namespace std;

int t,n,x;
long long sum = 0;
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);


    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<long long,vector<long long>,greater<long long> > pq;
        for (int i= 0;i<n;i++) {
            cin >> x;
            pq.push(x);
        }
        sum = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            a += pq.top(); pq.pop();
            sum += a;
            pq.push(a);
        }
        cout << sum <<'\n';
    }
}
/*
1. 파일 합치기 3
    - 카드 정렬하기와 같은 문제임.
*/
