// Authored by : keyboardmunji
// Created on 2025-06-02.
#include <bits/stdc++.h>
using namespace std;

int n,m,p,l,g,x;
set <int> s1[101][101]; // g,i에 p를 저장 , recommend1용
pair<int,int> s2[100001]; // p -> g,l 저장. solved용
set <int> s3[101]; // l에 따른 set recommend2.3용
string s;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0; i< n; i++) {
        cin >> p >> l >> g;
        s1[g][l].insert(p);
        s2[p] = {g,l};
        s3[l].insert(p);
    }
    cin >> m;
    for (int i =0;i <m;i++) {
        cin >> s;
        if (s == "recommend") {
            cin >> g >> x;
            if (x == 1) {
                for (int j = 100; j >= 1;j--) {
                    if (!s1[g][j].empty()) {
                        cout << *prev(s1[g][j].end()) <<'\n';
                        break;
                    }
                }
            }else {
                for (int j = 1; j<= 100;j++) {
                    if (!s1[g][j].empty()) {
                        cout << *s1[g][j].begin() <<'\n';
                        break;
                    }
                }
            }
        }else if (s == "recommend2") {
            cin >> x;
            if (x == 1) {
                for (int j = 100;j>=1;j--) {
                    if (!s3[j].empty()) {
                        cout << *prev(s3[j].end()) <<'\n';
                        break;
                    }
                }
            }else {
                for (int j = 1; j<= 100;j++) {
                    if (!s3[j].empty()) {
                        cout << *s3[j].begin() <<'\n';
                        break;
                    }
                }
            }
        }else if (s == "recommend3") {
            cin >> x >> l;
            bool ch = true;
            if (x == 1) {
                for (int j = l;j<=100;j++) {
                    if (!s3[j].empty()) {
                        cout << *s3[j].begin() <<'\n';
                        ch = false;
                        break;
                    }
                }
            }else {
                for (int j = l - 1;j>= 1;j--) {
                    if (!s3[j].empty()) {
                        cout << *prev(s3[j].end()) <<'\n';
                        ch = false;
                        break;
                    }
                }
            }
            if (ch)
                cout << -1 <<'\n';
        }else if (s == "add") {
            cin >> p >> l >> g;
            s1[g][l].insert(p);
            s2[p] = {g,l};
            s3[l].insert(p);
        }else {
            cin >> p;
            int a,b;
            tie(a,b) = s2[p];
            s1[a][b].erase(s1[a][b].find(p));
            s3[b].erase(s3[b].find(p));
        }
    }
}
/*
3. 문제 추천 시스템 version2
    - 알고리즘 분류 G가 늘었음.G 는 중복가능.
    - 그러면 2차 set으로 만들면 되는거 아닌가?
        - i → G, j → 난이도
    - 1차 set도 만들어야할 듯. recommend2,3을 효율적으로 처리하기 위해서.
    - 시간복잡도만 생각해보면 될듯
    - recommend1,3 : O(101)
    - add -> log n
    -> solved -> log n
*/
