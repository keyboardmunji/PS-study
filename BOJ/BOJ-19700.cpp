// Authored by : keyboardmunji
// Created on 2025-06-02.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
pair<int,int> stu[500001];
multiset<int> t;
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i<n;i++) cin >> stu[i].X >> stu[i].Y;
    sort(stu,stu+n,greater<pair<int,int>>());
    t.insert(1);
    for (int i =1 ;i<n;i++) {
        auto it = t.upper_bound(stu[i].Y-1);
        if (it == t.begin()) {
            t.insert(1);
        }
        else {
            --it;
            t.insert(*it + 1);
            t.erase(it);
        }
    }
    cout << t.size();
}
/*
1. 수업
   - 자기보다 키가 크면 불편해함. -> 따라서 방향성이 있음.
   - 큰 애 기준으로 만들어보자.
   - 큰애 기준으로 sort한 후 하나씩 대입 할 예정임.
   - size가 k보다 작으면 넣을 수 있음. + 작으면서 넣을 수 있는 곳중 size가 가장 큰곳에 가야함.
        - 즉, k-1에 대해 upper_bound를 하면 됨.
   - 이렇게 개수가 몇개 만들어 지는지 multiset으로 확인할 것임.
        - why? -> 현재 존재하는 팀의 upper_bound를 알아야함. -> multiset으로 하면 편함.
*/
