#include <bits/stdc++.h>

using namespace std;
int n, m, q;
bool arr[100001];
int vis[100001];
bool ans[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    vector <vector<int>> map (n + 1);
    for (int i = 1;i <= n;i++)
        cin >> arr[i];
    for (int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    for (int i = 1;i <= n;i++) {
        if (vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        int sum = arr[i] == 0 ? -1 : 1;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            int len = map[c].size();
            for (int i = 0;i < len;i++) {
                if (vis[map[c][i]]) continue;
                vis[map[c][i]] = 1;
                q.push(map[c][i]);
                sum += arr[map[c][i]] == 0 ? -1 : 1;
            }
        }
        q.push(i);
        vis[i] = 2;
        sum = sum > 0 ? 1 : 0;
        ans[i] = sum;
        while (!q.empty())
        {
            int c = q.front(); q.pop();
            int len = map[c].size();
            for (int i = 0;i < len;i++) {
                if (vis[map[c][i]] != 1) continue;
                vis[map[c][i]] = 2;
                q.push(map[c][i]);
                ans[map[c][i]] = sum;
            }
        }
    }
    for (int i = 0;i < q;i++) {
        int x;
        cin >> x;
        cout << ans[x] <<'\n';
    }

    return 0;
}
/*
1. 가능한 모든 파이프를 거쳐 탐색함.
    bfs라고 생각.
2. bfs의 시간복잡도는 O(n)임. 따라서, 가능!
3. Q가 10만이니, 물어볼 때마다, bfs를 도는것이 아니라, bfs를 미리 돌아두고, q를 물어볼때만 하면 O(n)에 처리가능.
*/