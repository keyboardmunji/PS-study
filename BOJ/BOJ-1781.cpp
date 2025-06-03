// Authored by : keyboardmunji
// Created on 2025-06-03.
#include <bits/stdc++.h>
using namespace std;

int n,sum;
pair<int,int> arr[200001];
priority_queue<int,vector<int>,greater<int>> minHeap;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i< n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr,arr+n);
    for (int i =0; i< n;i++) {
        if (arr[i].first > minHeap.size()) {
            minHeap.push(arr[i].second);
            sum += arr[i].second;
        }
        else {
            if (minHeap.top() < arr[i].second) {
                sum -= minHeap.top();
                minHeap.pop();
                minHeap.push(arr[i].second);
                sum += arr[i].second;
            }
        }
    }
    cout << sum;
}
/*
1. 컵라면
    - 일단 컵라면 개수가 많은 것들을 우선적으로 받아야함.
    - 고민은 데드라인을 어떻게 처리할지 임.
    - 음.. 그냥 데드라인으로 오름차순 으로 정렬하고, 최소힙으로 최소를 빼고 교체하는 식으로 할까
    - 데드라인이 사이즈랑 같을 때 최소힙에 있는 top이 x보다 컵라면 개수가 적으면 switching 하는 거지.
*/
