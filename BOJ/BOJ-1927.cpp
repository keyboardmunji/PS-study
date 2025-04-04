// Authored by : keyboardmunji
// Created on 2025-04-04.
#include <bits/stdc++.h>

using namespace std;

int heap[100005] = { -1, };
int sz = 0;

void push(int num) {
    heap[++sz] = num;
    int i = sz;
    while (i != 1) {
        if (heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
        else
            break;
    }
}

void top() {
    if(sz != 0)
        cout << heap[1] << '\n';
}
void pop() {
    if (sz == 0)
        cout << '0' << '\n';
    else {
        heap[1] = heap[sz--];
        int mn = heap[1];
        int i = 1,idx;
        while (1) {
            mn = heap[i];
            idx = i;
            if (i*2 <= sz && mn > heap[i * 2]) {
                mn = heap[i * 2];
                idx = i * 2;
            }
            if (i*2+1<= sz && mn > heap[i * 2 + 1]) {
                mn = heap[i * 2 + 1];
                idx = i * 2 + 1;
            }
            if (idx == i)
                break;
            else {
                swap(heap[i], heap[idx]);
                i = idx;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (num) {
            push(num);
        }
        else {
            top();
            pop();
        }
    }
    return 0;
}
/*
1. 최소 힙 구현
*/