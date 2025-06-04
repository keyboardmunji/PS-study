// Authored by : keyboardmunji,
// Created on 2025-06-04.
#include <bits/stdc++.h>
using namespace std;

int lc[27],rc[27],pr[27];
int n;
char a,b,c;

void func1(int node) { //전위 순회
    if (node == 0) return;
    cout << (char)(node + 'A' - 1);
    func1(lc[node]);
    func1(rc[node]);
}

void func2(int node) { // 중위 순회
    if (node == 0) return;
    func2(lc[node]);
    cout << (char)(node + 'A' - 1);
    func2(rc[node]);
}

void func3(int node) {
    if (node == 0) return;
    func3(lc[node]);
    func3(rc[node]);
    cout << (char)(node + 'A' - 1);
}
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0 ;i<n; i++) {
        cin >> a >> b >> c;
        if (b != '.') {
            lc[a-'A' + 1] = b - 'A' + 1;
            pr[b-'A'+1] = a-'A'+1;
        }
        if (c != '.') {
            rc[a-'A'+1] = c - 'A'+ 1;
            pr[c-'A'+1] = a-'A' + 1;
        }
    }
    func1(1);
    cout << '\n';
    func2(1);
    cout <<'\n';
    func3(1);
    cout <<'\n';
}
/*
1. 트리 순회
    - 항상 A가 루트라 A 기준으로 각각 전위,중위,후위 순회하면 됨.
*/
