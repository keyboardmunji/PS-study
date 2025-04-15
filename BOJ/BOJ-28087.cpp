// Authored by : keyboardmunji
// Created on 2025-04-15.
#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int> s[5000001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0;i<m;i++) {
        cin >> s[i].first;
        s[i].second = i + 1;
    }
    sort(s, s+m,greater<pair<int,int>>());
    int en = 2*n,sum = 0;
    vector<int> ans;
    for (int i =0;i<m;i++) {
        if (s[i].first > en) continue;
        else if (s[i].first <= en && s[i].first >= n) {
            cout <<"1\n" << s[i].second;
            return 0;
        }
        else {
            ans.push_back(s[i].second);
            sum += s[i].first;
        }
        if (sum >= n)
            break;
    }
    int len = ans.size();
    cout << len <<'\n';
    for (int i =0;i<len;i++)
        cout << ans[i] <<'\n';
    return 0;
}

/*
 1. s가 2n보다 큰 경우 -> 안됨.
 2.  n <= s <= 2n인 경우 그냥 1개만 출력하면 됨.
 3. s < n인 경우 -> 가장 큰 값을 계속 더하면 됨.
 why? -> s < n인 s중 아무런 수가 x,y가 있다고 생각해보자.
 x +y <= 2n임. 따라서 무조건 성립함.
*/

