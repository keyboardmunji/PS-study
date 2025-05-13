// Authored by : keyboardmunji
// Created on 2025-05-13.
#include <bits/stdc++.h>
using namespace std;

int t;
int cnt = 1;
int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (cnt <= t) {
        int n;
        cin>> n;
        vector<int> v(n);
        for (int i =0;i<n;i++)
            cin >> v[i];
        int len = n;
        while (len != 2) {
            int half = len / 2;
            for (int i = half;i<len;i++)
                v[len - i - 1] += v[i];
            len = (len+1)/2;
        }
        cout <<"Case #" <<cnt <<": ";
        if (v[0] > v[1])
            cout << "Alice\n";
        else
            cout << "Bob\n";
        cnt++;
    }

    return 0;
}
/*
1. 시뮬레이션
*/