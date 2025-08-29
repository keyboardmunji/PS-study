// Authored by : keyboardmunji
// Created on 2025-08-30.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

const long long MX = 200000LL * 1000000000LL + 1;
int n, m, a, b, c, cnt;
bool note[200001];
vector<pair<long long, int>> v[200001];
vector<long long> val(200001, MX);
vector<int> note_cnt(200001, 0);
vector<int> pre(200001, 0);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({(long long)c, b});
        v[b].push_back({(long long)c, a});
    }

    for (int i = 1; i <= n; i++) {
        cin >> note[i];
        if (note[i] == 1) cnt++;
    }

    val[1] = 0;
    pre[1] = 1;
    note_cnt[1] = note[1];

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({val[1], -note_cnt[1], 1});

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        long long current_cost;
        int current_notes_neg, current_node;
        tie(current_cost, current_notes_neg, current_node) = t;

        if (current_cost > val[current_node] || -current_notes_neg > note_cnt[current_node]) {
            continue;
        }

        for (auto p : v[current_node]) {
            long long new_cost = current_cost + p.first;
            int new_notes = -current_notes_neg + note[p.second];

            if (new_cost < val[p.second]) {
                val[p.second] = new_cost;
                note_cnt[p.second] = new_notes;
                pre[p.second] = current_node;
                pq.push({val[p.second], -note_cnt[p.second], p.second});
            } else if (new_cost == val[p.second] && new_notes > note_cnt[p.second]) {
                note_cnt[p.second] = new_notes;
                pre[p.second] = current_node;
                pq.push({val[p.second], -note_cnt[p.second], p.second});
            }
        }
    }

    if (note_cnt[n] != cnt) {
        cout << -1;
        return 0;
    }

    vector<int> ans;
    int x = n;
    while (x != 1) {
        ans.push_back(x);
        x = pre[x];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}
/*
- 노트 조각

*/