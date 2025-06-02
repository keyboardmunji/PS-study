// Authored by : keyboardmunji
// Created on 2025-06-02.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,k;
pair <int,int> jw[300001];
multiset<int> bag;
long long val;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i =0; i<n;i++)
        cin >> jw[i].Y >> jw[i].X;
    sort(jw,jw+n,greater<>());
    for (int i =0 ;i <k;i++) {
        int num;
        cin >> num;
        bag.insert(num);
    }
    for (int i =0; i<n;i++) {
        if (bag.find(jw[i].Y) != bag.end()) {
            val += jw[i].X;
            bag.erase(bag.find(jw[i].Y));
        }else if (bag.upper_bound(jw[i].Y) != bag.end()) {
            val += jw[i].X;
            bag.erase(bag.upper_bound(jw[i].Y));
        }
    }
    cout << val;
}
/*
1. n개의 보석, k개의 가방.
2. 최대 가격이 되게끔, 하고싶음. -> 따라서 무게(-), 가격(+) 요소, 단 각 상황마다 뭐가 더 우선시 될지는 다름.
3. 30만이라 최대 nlogn에 풀어야할듯. 근데, 각 가방에는 1개의 보석만 넣을 수 있음. -> 따라서 가장 가치가 높을 것 같은걸 담아야함.
4. 일단, 가방 무게를 기준으로 오름차순 sort -> 가치가 높은것 , 무게가 높은것으로 sort함. -> 그럼 첫번째 가방에 못들어 가는건, 나머지 가방에도 못들어감.
5. 그다음 가방을 기준으로 이분탐색 돌리면 되는데, 쓴 가방을 지우려고 하기에 multiset이 좋을듯.
*/