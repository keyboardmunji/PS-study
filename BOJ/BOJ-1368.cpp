// Authored by : keyboardmunji,
// Created on 2025-06-18.
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int n,x;
bool vis[301];
int pr[301][301];
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> price;
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i<=n;i++) {
        cin >> x;
        price.push({x,i});
    }
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++) cin >> pr[i][j];
    int cnt = 1, pre = price.top().Y, sum = price.top().X; price.pop();
    vis[pre] = true;
    while (cnt < n) {
        for (int i = 1;i<=n;i++) {
            if (pre == i || vis[i] == true) continue;
            pq.push({pr[pre][i],i});
        }
        while (vis[pq.top().Y])
            pq.pop();
        while (vis[price.top().Y])
            price.pop();
        if (pq.top().X > price.top().X) {
            pre = price.top().Y;
            sum += price.top().X;
            price.pop();
        }else {
            pre = pq.top().Y;
            sum += pq.top().X;
            pq.pop();
        }
        vis[pre] = true;
        cnt++;
    }
    cout << sum;
}
/*
1. 물대기
    - 그리디를 통해 풀 예정임.
    - 우선 정점의 최솟값을 담는 우선순위 큐를 만들고, 정점의 최솟값을 방문했다고 체크 함.
    - 이제, 정점의 최솟값과, 현재까지 포함한 정점들과 연결되어있는 간선들 중 비용이 가장 작은 것과 비교함.
    - 그렇게 정점 혹은 간선들을 선택하면서 정점을 다 선택하면 종료 됨.
*/
