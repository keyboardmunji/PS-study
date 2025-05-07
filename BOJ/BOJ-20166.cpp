// Authored by : keyboardmunji
// Created on 2025-05-07.
#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s[10];
int dx[8] = {-1,-1,-1,1,1,1,0,0};
int dy[8] = {-1,0,1,-1,0,1,-1,1};

unordered_map<string,int> d;

void dfs(int x,int y, string a) {
    d[a]++;
    if (a.length() == 5)
        return;
    for (int i = 0; i <8;i++) {
        int x1 = (x + dx[i] + n) % n;
        int y1 = (y + dy[i] + m) % m;
        dfs(x1,y1, a+string(1,s[x1][y1]));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>  n >> m >> k;
    for (int i= 0;i<n;i++) cin >> s[i];
    for (int i = 0;i<n;i++)
        for (int j =0;j<m;j++)
            dfs(i,j,string(1,s[i][j]));
    for (int i =0;i<k;i++) {
        string q;
        cin >> q;
        cout << d[q] <<'\n';
    }
    return 0;
}
/*
1. 입력받음.
2. 각 위치마다 2개의 연결된 문자열을 구할 것임. -> ab 이런 것들에 a의 좌표를 매핑함. O(NM)
3. 신이 준 문자열을 연결된 2개의 부분 문자열로 분리해서 계산 시작. like 버블 정렬
    ex) abcde의 경우
        1. ab, bc로 쪼개짐. 그러면 ba 와 bc의 교집합을 찾으면 되긴함. -> O(NM)
        2. 이를 4번 반복 -> O(NM) 반복해서 나온 집합의 개수가 경우의수임.
    이를 K번 반복함으로 O(NMK)가 시간 복잡도인듯.
엄청 복잡하게 푸는 느낌이 들긴함. -> 걍 브루트포스로 하면 안되나. -> 그게 맞았노 ㄹㅇ
*/