// Authored by : keyboardmunji
// Created on 2025-04-09.
#include <bits/stdc++.h>

using namespace std;
int n,m;
bool arr[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    vector<int> ans;
    cin >> m >> n;

    for (int i =2;i <=n;i++) {
        if (arr[i] == 1) continue;
        if (i >= m)
            ans.push_back(i);
        for (int j = i*i; j<=n;j+=i)
            arr[j] = 1;
    }
    if (ans.empty())
        cout << "-1";
    else {
        int sum = 0;
        for (int i =0;i<ans.size();i++)
            sum += ans[i];
        cout << sum <<'\n' << ans[0];
    }

    return 0;
}

/*
 1. 범위에 있는 소수를 판별하는 것이므로 에라토스테네스의 체를 이용하여 구함.

*/

