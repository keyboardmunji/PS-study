#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int n;
pair<int,int> arr[101];
int d[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        arr[i] = {x,y};
    }
    sort(arr,arr+n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i].Y > arr[j].Y)
                d[i] = max(d[i], d[j] + 1);
        }
        mx = max(mx, d[i]);
    }
    cout << n - mx;

    return 0;
}

/*
 1. 전깃줄
    - pair로 sort하고, 그 뒤에 second를 기준으로 Lis를 구하면 될듯.
*/