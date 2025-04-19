// Authored by : keyboardmunji
// Created on 2025-04-18.
#include <bits/stdc++.h>
using namespace std;

int n;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<pair<int,int>> ans;
    for (int i = 0;i<n-1;i++) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1;i<=n;i++)
        sort(v[i].begin(),v[i].end());

    if (n == 2) {
        cout << 0 <<'\n' << 1;
        return 0;
    }
    else if (n == 3 || n == 4) {
        for (int i =1;i<=n;i++) {
            vector<bool> vis(n+1,false);
            vis[i] = true;
            for (int j =0;j<v[i].size();j++)
                vis[v[i][j]] = true;
            for (int j =1; j<=n;j++) {
                if (vis[j] == true) continue;
                v[i].push_back(j);
                v[j].push_back(i);
                ans.push_back({i,j});
            }
        }
        cout << ans.size() << "\n" << 1<<'\n';
        for (int i =0;i<ans.size();i++) cout << ans[i].first<<' '<<ans[i].second <<'\n';
    }else {
        int mx = 0,idx;
        for (int i =1;i<=n;i++) {
            if (mx < v[i].size()) {
                mx = v[i].size();
                idx = i;
            }
        }
        vector<bool> vis(n+1,false);
        vis[idx] = true;
        for (int i = 0;i<v[idx].size();i++)
            vis[v[idx][i]] = true;
        for (int i =1;i<=n;i++) {
            if (vis[i]) continue;
            ans.push_back({idx,i});
        }
        cout << ans.size() <<'\n'<< 2 <<'\n';
        for (int i =0;i<ans.size();i++)
            cout << ans[i].first <<' ' << ans[i].second <<'\n';
    }
    return 0;
}
/*
주어진 입력값은 노드 번호만 때고 보면 선형그래프 아님.ㅋㅋㅋㅋ 쓰벌
각 가지가 더 있을 수 있음.
그렇다면 가지를 어떻게 처리할까?
각 가지를 따로 볼까? -> 이래도 nC2임.
? 그냥 한 정점이 모든 노드를 참조하면 되는거 아닌가? 그러면 무조건 2번안에 가능
ㅇㅎ! 그러면 구름다리의 개수의 최소도 결정됨 개꿀딱따구리
그러면 1. 가장 많은 벡터 사이즈를 들고 있는 것을 찾는다.
그게 포함하지 않는 것들을 추가한다.
개ㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐ꿀띠
일단 최대 지름이 2라는것이 보장됨. -> 바퀴처럼 연결하면 -> 연결된 개수가 2(n-1)이라 그런것.
그렇다면 2(n-1) <= nC2 인 순간을 알아야함.

2(n-1) <= n(n-1)/2
4(n-1) <= n(n-1)
(n-1)(n-4) >= 0
즉, 5이상 부터는 바퀴처럼 연결
2, 3,4 일떄는 예외처리.



-----
구현 방식
-> vector를 통해서 그래프를 입력받음.
*/