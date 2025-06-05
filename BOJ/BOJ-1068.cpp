// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
using namespace std;

int n,r,e,x,cnt;
vector<vector<int>> v;

void func1(int node){
    int count = 0;
    for (auto c : v[node]) {
        if (c == e) continue;
        count ++;
        func1(c);
    }
    if (count == 0) cnt++;
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (int i =0;i < n;i++) {
        cin >> x;
        if (x == -1)
            r = i;
        else
            v[x].push_back(i);
    }
    cin >> e;
    if (r == e) {
        cout << 0;
        return 0;
    }
    func1(r);
    cout << cnt;
}
/*
1. 트리
    - 받을 때 c를 벡터로 받고, root부터 순회를 시작한다.
    - 단 자식 노드로 지울 노드가 나왔을 때 continue를 해주면 될듯.
*/
