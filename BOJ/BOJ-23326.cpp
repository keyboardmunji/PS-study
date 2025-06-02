// Authored by : keyboardmunji
// Created on 2025-06-02.
#include <bits/stdc++.h>
using namespace std;

int n,q,a,x;
bool mp[500001];
set<int> s;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i =0; i< n;i++) {
        cin>> mp[i];
        if (mp[i] == 1)
            s.insert(i);
    }
    int l = 0;
    for (int i =0; i<q;i++) {
        cin >> a;
        if (a == 1) {
            cin >> x;
            if (mp[x-1] == 1)
                s.erase(s.find(x-1));
            else
                s.insert(x-1);
            mp[x-1] = !mp[x-1];
        }else if (a == 2) {
            cin >> x;
            l = (l + x) % n;
        }else {
            if (s.empty()) {
                cout << -1 <<'\n';
                continue;
            }
            if (s.lower_bound(l) == s.end())
                cout << *s.begin() + n - l <<'\n';
            else
                cout << *s.lower_bound(l) - l <<'\n';
        }
    }

}
/*
2. 홍익 투어리스트
    - 명소의 인덱스를 set으로 저장 → lower_bound로 가장 가까운 명소의 인덱스를 찾음. → 원형이라 lower_bound는 빡센가. nono → lower_bound값이 없을 때 이므로 가장 작은 값을 넘겨주면 됨.
    - 1 → log n에 set에 있는 원소를 지우거나 추가함.
    - 2 → O(1)로 이동함.
*/