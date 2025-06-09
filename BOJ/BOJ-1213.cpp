// Authored by : keyboardmunji,
// Created on 2025-06-10.
#include <bits/stdc++.h>

using namespace std;

string s;
int alpha[26];
int cnt,idx,st;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int len = s.length();
    for (int i =0 ;i<len;i++)
        alpha[s[i]-'A']++;
    for (int i =0; i< 26;i++) {
        if (alpha[i]%2) {
            cnt++;
            idx = i;
        }
    }
    if (cnt > 1) {
        cout << "I\'m Sorry Hansoo";
        return 0;
    }
    vector<char> ans(len);
    for (int i =0; i<26;i++) {
        while (alpha[i] > 1) {
            ans[st] = ans[len - st - 1] = char(i + 'A');
            st++;
            alpha[i] -= 2;
        }
    }
    if (len % 2)
        ans[st] = char(idx + 'A');
    for (auto c: ans)
        cout << c;
}
/*
1. 팰린드롬 만들기
    - 일단 각 알파벳의 개수를 센다.
    - 홀수개는 최대 1개여야한다. -> 2개면 절대 만들 수 없다.
    - 그 다음 사전순으로 하나씩 앞과 뒤에 넣는다.
    - 홀수개일 때 홀수인것을 가운데에 넣는다.
*/
