// Authored by : keyboardmunji
// Created on 2025-06-03.
#include <bits/stdc++.h>
using namespace std;

int n,x,mid;
priority_queue<int> maxQ;
priority_queue<int,vector<int>,greater<int>> minQ;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=1;i <=n;i++){
        cin >> x;
        if (i == 1) {
            mid = x;
            cout << mid <<'\n';
            continue;
        }
        if (x > mid)
            minQ.push(x);
        else
            maxQ.push(x);
        if (minQ.size() < maxQ.size()) {
            int t = maxQ.top();
            maxQ.pop();
            minQ.push(mid);
            mid = t;
        }else if (minQ.size() > maxQ.size() + 1) {
            int t = minQ.top();
            minQ.pop();
            maxQ.push(mid);
            mid = t;
        }
        cout << mid << '\n';
    }
}
/*
1. 가운데를 말해요
    - 첫번째로 받은 값을 중간값으로 둠.
    - if 중간값보다 큰 값이 들어왔을 경우 -> 최소힙에 넣음. 이건 중간 값보다 큰 값중 가장 작은 값이라는 의미임.
    - if 중간값보다 작거나 같은 값이 들어왔을 경우 -> 중간 값보다 작은 최대 힙에 값을 넣음.
    - 왜 이렇게 할까? -> 이 문제에서 중간값의 정의는 자신보다 큰 값의 개수 - 작은 값의 개수 <= 1임. 따라서 개수를 알아야 함.
    - 그럼 언제 값을 바꾼다는 걸까?
    - if 큰 값의 개수가 작은 값의 개수보다 2 클 때 -> 최소힙에 있는 top을 pop하고, 지금 중간값은 최대힙에 넣음. 그러고 top에 있는 걸 중간으로
    - if 작은 값의 개수가 큰 값의 개수보다 클 떄 -> 최대힙에 있는 top을 pop하고, 중간값으로 만듬. 중간값은 최소힙에 넣음.
*/
