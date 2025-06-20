// Authored by : keyboardmunji,
// Created on 2025-06-20.
#include <bits/stdc++.h>
using namespace std;

int n,m,l,x;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> l;
    vector<int> v;
    for (int i = 0; i< n ;i++) {
        cin >> x;
        v.push_back(x);
    }
    v.push_back(l);
    sort(v.begin(), v.end());
    int st = 1, ed = l,mid, ans = l;
    while (st <= ed && st > 0) {
        mid = (st + ed) / 2;
        int cnt = 0,ex = 0;
        for (int i = 0; i<= n; i++) {
            if (ex + mid < v[i]) {
                ex += mid;
                cnt++;
                i--;
            }else
                ex = v[i];
        }
        if (cnt > m)
            st = mid + 1;
        else {
            ans = min(ans,mid);
            ed = mid - 1;
        }
    }
    cout << ans;
}

/*
1. 휴게소 세우기
    - 현재 휴게소가 있는곳, 끝에 못 지음.
    - parametric search로 지으면 될듯.
*/
