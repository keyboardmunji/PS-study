// Authored by : keyboardmunji
// Created on 2025-06-02.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m,p,l,x,idx;
set <int> m1[101];
int m2[100001];
string q;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i= 0;i<n;i++) {
        cin >> p >> l;
        m2[p] = l;
        m1[l].insert(p);
    }
    cin >> m;
    for (int i =0;i<m;i++) {
        cin >> q;
        if (q == "add") {
            cin >> p >> l;
            m2[p] =l;
            m1[l].insert(p);
        }else if (q == "solved") {
            cin >> p;
            m1[m2[p]].erase(m1[m2[p]].find(p));
        }else{
            cin >> x;
            if (x == 1) {
                for (int i = 100; i >= 1;i--) {
                    if (!m1[i].empty()) {
                        idx = i;
                        break;
                    }
                }
                cout << *prev(m1[idx].end()) << '\n';
            }else {
                for (int i =1;i<= 100;i++) {
                    if (!m1[i].empty()) {
                        idx = i;
                        break;
                    }
                }
                cout << *m1[idx].begin() <<'\n';
            }
        }
    }
}
/*
1. 문제 추천 시스템 version1
    - set을 배열로 만들어서 난이도 idx에 마다 set을 만듬.
    - 배열로 p문제에 난이도를 담는 배열 생성
    - recommend → set중 empty가 아닌 set의 최대 idx를 찾고 하나 출력
    - add → set에 추가.
    - solved → 배열에서 난이도 찾고 → set에서 제거.
    - 시간 복잡도 → mlogn 정도 인듯
*/