// Authored by : keyboardmunji
// Created on 2025-04-07.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
pair<int,int> arr[1001];
int score[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0;i<n;i++)
        cin >> arr[i].Y >> arr[i].X;

    sort(arr,arr+n,greater<pair<int,int>>());

    for (int i= 0;i<n;i++) {
        while (arr[i].Y != 0) {
            if (score[arr[i].Y] == 0) {
                score[arr[i].Y] = arr[i].X;
                break;
            }
            arr[i].Y--;
        }
    }
    int ans = 0;
    for (int i = 0;i<=1000;i++)
        ans += score[i];
    cout << ans;
    return 0;
}

/*
 1. 하루에 1개의 과제를 클리어 할 수 있음. 따라서 가장 점수를 많이 받게 과제를 설계하고 싶음.
 2. d : 과제 마감일, w : 과제의 점수
 3. 과제의 남은 마감일이 중요할까, 아니면 과제의 점수가 중요할까?
 4. ex1 ) 4 10 , 4 10 , 1 5 일때 1 5 , 4 10 , 4 10 순서 대로 해야하므로 날짜가 중요해보인다.
 5. ex2 ) 예제 1번입력과 같은 경우엔 점수기준으로 생각하는게 더 이득이다.
 6. 차이가 뭘까? -> 점수가 높은 것들을 처리한 후 남은걸 처리할 수 있냐 없냐 차이인듯.
*/

