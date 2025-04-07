#include <bits/stdc++.h>

using namespace std;

int n, m;
bool arr[4001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> arr[i];
    for (int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            arr[b] = c;
        else if (a == 2)
            for (int j = b;j <= c;j++)
                arr[j] = !arr[j];
        else if (a == 3)
            for (int j = b;j <= c;j++)
                arr[j] = false;
        else
            for (int j = b;j <= c;j++)
                arr[j] = true;
    }
    for (int i = 1;i <= n;i++)
        cout << arr[i] << ' ';
    return 0;
}
/*
그냥 시키는 대로 구현해도 될듯.

*/