// Authored by : keyboardmunji
// Created on 2025-06-28.
#include <bits/stdc++.h>
using namespace std;

int n,k,mn = 10001;
int mp[11][11];
int nxt[11][11];
bool vis[11];

void func1(int x,int sum) {
    bool ch = false;
    bool box[11];
    for (int i =0 ; i< n;i++) {
        if (vis[i] == false)
            ch = true;
        box[i] = vis[i];
    }
    if (!ch) {
        mn = min(mn,sum);
        return;
    }
    for (int i = 0; i< n;i++) {
        if (vis[i] == false) {
            vis[i] = true;
            int st = nxt[x][i];
            while (st != i) {
                vis[st] = true;
                st = nxt[st][i];
            }
            func1(i,sum + mp[x][i]);
            for (int j = 0; j< n;j++)
                vis[j] = box[j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i =0 ; i< n;i++) {
        for (int j = 0;j<n;j++) {
            cin >> mp[i][j];
            nxt[i][j] = j;
        }
    }
    for (int i =  0;i<n;i++) {
        for (int j = 0; j<n;j++) {
            for (int k = 0;k<n;k++) {
                if (mp[j][k] > mp[j][i] + mp[i][k]) {
                    mp[j][k] = mp[j][i] + mp[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }
    func1(k,0);
    cout << mn;

    return 0;
}
/*
1. 우주 탐사선
    - 모든 행성을 탐사하는데 걸리는 최소시간을 어떻게 구할까?
    - 그러면 10!로 모든 경우를 구한 후 그에 맞는 길로 가면 어떨까..?
    - 음.. 근데, 무조건 거쳐야 하는 길은 어떻게 처리하지?
    - 약간 A에서 난 B를 가고 싶어. 근데 B를 가려면 C를 거치는게 더 좋네? 이런 것 처럼
    - 플로이드는 걸쳐온 길을 따로 조사하진 않잖아. 대신 nxt배열로 어디 가면 좋을지는 가능하지.
    - 백트래킹 + 플로이드로 풀어봐야할듯..
*/