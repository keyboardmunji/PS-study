#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int coin[101];
ll arr[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    for (int i = 0; i < n; i++) {
        arr[coin[i]] += 1;
        for (int j = 1; j <= k; j++)
            if (j > coin[i])
                arr[j] += arr[j - coin[i]];
    }
    cout << arr[k];
    return 0;
}

/*
 1. 동전
    - 1의 자리의 5로 나눈 나머지를 처리하고 나면, 1,2,3 더하기랑 동일한 문제로 치환 되는 것 같음.
    - 근데, 차이점은 순서고려를 안하는 조합임.
    - 이를 해결하는 방식이 1먼저 채우고, 2먼저 채우고 3을 채우는 방식이라고 함. (이건 좀 신기함.)
    - 시간복잡도는 O(NM)
*/