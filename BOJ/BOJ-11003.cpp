// Authored by : keyboardmunji
// Created on 2025-07-20.
#include <bits/stdc++.h>
using namespace std;

int n, l, x;
int arr[5000001];
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;
    deque<int> d;
    for (int i = 1; i<= n; i++)
        cin >> arr[i];
    for (int i = 1;i<=n;i++) {
        if (!d.empty() && d.front() == i - l)
            d.pop_front();
        while (!d.empty() && arr[d.back()] > arr[i])
            d.pop_back();
        d.push_back(i);
        cout << arr[d.front()] << ' ';
    }
}

/*
1. 최솟값 찾기.
    - 슬라이딩 윈도우 연습하기.
    - 덱이랑 활용해서 고정 윈도우 내의 최대 최소를 O(n)에 구할 수 있음.
*/