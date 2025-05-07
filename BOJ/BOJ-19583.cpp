// Authored by : keyboardmunji
// Created on 2025-05-07.
#include <bits/stdc++.h>
using namespace std;

string s,e,q,a,b;
int cnt;
unordered_set<string> name;
unordered_set<string> ch;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> e >> q;
    while (cin >> a) {
        cin >> b;
        if (a <= s)
            name.insert(b);
        else if (a >= e && a <= q && !ch.count(b)) {
            if (name.find(b) != name.end()) {
                cnt++;
                ch.insert(b);
            }
        }
    }
    cout << cnt;
    return 0;
}
/*
1. 문자열로 대소 비교 해도 됨.
2. 채팅기록이 순서대로 주어짐. -> s보다 작을때 셋에 추가
3. e보다 크고 q보다 작을때 셋에 주어진 이름이 존재하는지 확인. -> 있으면 cnt추가
4. ** 출석자 셋을 따로 만들어서 사이즈만 측정해도됨. -> 중복제거니까
*/