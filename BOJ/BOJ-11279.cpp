// Authored by : keyboardmunji
// Created on 2025-04-05.
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (num) {
            pq.push(num);
        }
        else {
            if (pq.empty())
                cout << '0' <<'\n';
            else {
                cout <<  pq.top() <<'\n';
                pq.pop();
            }
        }
    }
    return 0;
}
/*
1. stl을 활용한 최대 힙 구현
*/

