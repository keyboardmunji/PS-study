// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>

using namespace std;
int n,q,x1,x2,y;
vector<int> p(100001,-1);

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;
    if (p[u] > p[v])
        swap(u,v);
    if (p[u] == p[v])
        p[u]--;
    p[v] = u;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    vector<tuple<int,int,int>> v(n+1);
    for (int i = 1; i<= n;i++) {
        cin >> x1 >> x2 >> y;
        v[i] = {x1,x2,i};
    }
    sort(v.begin()+1,v.end());
    int ed = -1,idx;
    for (int i = 1;i<=n;i++) {
        if (ed >= get<0>(v[i])) {
            if (ed < get<1>(v[i]))
                ed = get<1>(v[i]);
            uni(idx,get<2>(v[i]));
        }else {
            ed = get<1>(v[i]);
            idx = get<2>(v[i]);
        }
    }
    for (int i = 0;i<q;i++) {
        cin >> x1 >> x2;
        cout << (find(x1) == find(x2)) <<'\n';
    }
}
/*
1. 개구리 점프
    - 다른 통나무 위를 지나면 안된다.라는 의미가 무엇일까? 왜 주어졌는지는 모르겠음.
    - 일단 x1,x2,통나무 번호를 tuple로 받고 정렬시킨다. y는 딱히 의미가 없음.
    - 그리고 i번째 통나무의 x2와 i+1번째 통나무의 x1을 비교하면서 연결되면 i와 i+1을 union한다.
    - 질문이 주어질때는 두 통나무가 같은 루트를 가지고 있는지 확인하면 된다.
    - Test Case에 sort가 되어있으면 sort가 안되어 있는 경우도 생각해보자.
*/
