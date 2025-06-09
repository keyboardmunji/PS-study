// Authored by : keyboardmunji,
// Created on 2025-06-09.
#include <bits/stdc++.h>
using namespace std;

int n,x;
bool arr[1000001];
int score[1000001];

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> v(n);
    for (int i =0 ;i< n;i++) {
        cin >> x;
        v[i] = x;
        arr[x] = true;
    }
    for (int i =0; i < n;i++) {
        for (int j = 1; j * j <= v[i];j++) {
            if (v[i] % j == 0) {
                if ((j == 1 || j * j == v[i]) && arr[j] == true) {
                    score[v[i]] -= 1;
                    score[j] += 1;
                    continue;
                }
                if (arr[j] == true) {
                    score[v[i]] -= 1;
                    score[j] += 1;
                }
                if (arr[v[i]/j] == true) {
                    score[v[i]] -= 1;
                    score[v[i]/j] += 1;
                }
            }
        }
    }
    for (int i = 0; i<n;i++)
        cout << score[v[i]] <<' ';

}
/*
1. 수 나누기 게임.
    - 걍 x있으면 x 약수 구하는 func 만들고, 그 약수가 리스트에 있는지 확인하면 될듯.
*/
