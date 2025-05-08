// Authored by : keyboardmunji
// Created on 2025-05-08.
#include <bits/stdc++.h>
using namespace std;

int n,t;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> t;
        multiset<int> s;
        while (t--) {
            char a;
            int b;
            cin >> a >> b;
            if (a == 'I')
                s.insert(b);
            else {
                if (s.empty()) continue;
                if (b == 1)
                    s.erase(prev(s.end()));
                else
                    s.erase(s.begin());
            }
        }
        if (s.empty()) cout << "EMPTY\n";
        else cout << *prev(s.end()) <<' ' << *s.begin() <<'\n';
    }
    return 0;
}
/*
1. 이진 검색 트리 활용
*/