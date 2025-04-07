#include <bits/stdc++.h>

using namespace std;

int n, m, st = 0, mx = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int x;
        cin >> x;
        if (i == 0)
            mx = x;
        else
            mx = max(mx, (x - st + 1) / 2);
        st = x;
    }
    mx = max(mx, n - st);
    cout << mx;
    return 0;
}
/*
1. 가로등의 위치를 오름차순으로 받는다.
2. 두 가로등의 거리차의 최대를 구한다.
3. 처음과 끝은 예외이며, 가로등과 가로등 사이의 거리는 (거리차 + 1)/2로 계산한다.
4. 따라서 시간복잡도는 O(m)이다.
*/