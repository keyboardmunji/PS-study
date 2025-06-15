// Authored by : keyboardmunji,
// Created on 2025-06-12.
#include <bits/stdc++.h>

using namespace std;
int t,n,k,m,x,y;
int p[1000001];

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;
    if (p[u] > p[v])
        swap(u, v);
    if (p[u] == p[v])
        p[u]--;
    p[v] = u;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    int cnt = 1;
    while (cnt <= t) {
        cin >> n >> k;
        fill(p,p+n,-1);
        for (int i =0 ;i<k;i++) {
            cin >> x >> y;
            uni(x,y);
        }
        cin >> m;
        cout << "Scenario " << cnt <<":\n" ;
        for (int i =0 ;i<m;i++) {
            cin >> x >> y;
            if (find (x) == find(y))
                cout << 1 <<'\n';
            else
                cout << 0 << '\n';
        }
        cnt++;
        cout <<'\n';
    }
}
/*
1. 소셜 네트워킹 어플리케이션
    - a와 b의 경로 연결되었다고 주어 졌을 때, union을 하면 됨.
    - 두번째는 find해주면 되고.
*/
