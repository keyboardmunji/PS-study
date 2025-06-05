// Authored by : keyboardmunji,
// Created on 2025-06-05.
#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,cnt;
int rc[100001];

void func(int node) {
    if (rc[node] != 0 ) {
        cnt++;
        func(rc[node]);
    }
}
int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0 ;i< n; i++) {
        cin >> a >> b >> c;
        if (c != -1)
            rc[a] = c;
    }
    func(1);
    cout << (long long)(n-1) * 2 - cnt;
}
/*
1. 트리 순회
    - 음.. rc로 몇번 내려갈 수 있는지 만 확인하면 될듯?
    - 왜 why? -> 결국 내려 갔다가 와야하는데 그럼 반복횟수는 무조건 2번이 되게 됨. -> 부모가 있을 경우
    - 그렇다면 1번이 되는 경우는 마지막 까지 도달한 경우인데, 마지막은 오른쪽으로 몇번 이동했는지임.
    - 따라서 (n-1) * 2 - cnt라는 뜻.
*/
