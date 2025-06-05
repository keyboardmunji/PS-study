// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
using namespace std;

int n,r,q,x,y;
vector<vector<int>> v;
vector<int> pr;
vector<vector<int>> ch;
vector<int> subsize;
void makeTree(int currentNode, int parent) {
    for (auto Node : v[currentNode]) {
        if (Node == parent) continue;
        ch[currentNode].push_back(Node);
        pr[Node] = currentNode;
        makeTree(Node, currentNode);
    }
}

void count(int currentNode) {
    subsize[currentNode] = 1;
    for (auto Node : ch[currentNode]) {
        count(Node);
        subsize[currentNode] += subsize[Node];
    }
}

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> q;
    v.resize(n+1);
    pr.resize(n+1);
    ch.resize(n+1);
    subsize.resize(n+1);
    for (int i =0; i<n-1;i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    makeTree(r,-1);
    count(r);
    for (int i =0; i<q;i++) {
        cin >> x;
        cout << subsize[x] <<'\n';
    }
}
/*
1. 트리와 쿼리
    - 문제 힌트에서 주어진대로 작성하면 될듯.
*/
