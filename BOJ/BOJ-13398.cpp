#include <bits/stdc++.h>

using namespace std;
int d[100001][2];
vector<int> arr;
int mx = -1001;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    mx = d[0][0] = arr[0];
    for (int i = 1; i < n; i++) {
        d[i][0] = max(d[i-1][0] + arr[i], arr[i]);
        d[i][1] = max(d[i-1][1] + arr[i], d[i-1][0]);
        mx = max({mx, d[i][1], d[i][0]});
    }
    cout << mx;
    return 0;
}

/*
 1. 연속합 2
    - 일단, 그냥 연속합은 D[i] = max(A(i) + D[i-1], A(i)) 이렇게 구하면됨.
    - 근데, 제거한다는 제한조건이 생김. 이를 하나하나 경우를 다 따지면 O(N^2)이니, 이를 D[i][0 or 1] 로 관리하면 될듯.
    - D[i][0] = max(A(i) + D[i-1][0], A(i)) , D[i][1] = max(D[i - 1][0], D[i-1][1] + A(i)) 이러면 될듯.
*/