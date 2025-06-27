// Authored by : keyboardmunji
// Created on 2025-06-27.
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> ans;

bool comp(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> s;
        int len = s.length();
        string b;
        for (int i = 0; i< len;i++) {
            if (i != len - 1 && b.empty() && s[i] == '0' && (s[i+1] >= '0' && s[i+1] <= '9')) continue;
            if (s[i] >= '0' && s[i] <= '9') {
                b += s[i];
            }else if (!b.empty()){
                ans.push_back(b);
                b.clear();
            }
        }
        if (!b.empty())
            ans.push_back(b);
    }
    sort(ans.begin(),ans.end(),comp);
    for (auto c : ans)
        cout << c <<'\n';

    return 0;
}
/*
1. 수학 숙제
    - 문자열에서 숫자 문자열을 뽑아내서 벡터에 저장 -> 정렬 -> 출력
    - 1007b같은건 17로 대답해야하나.
*/