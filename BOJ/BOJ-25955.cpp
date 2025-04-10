// Authored by : keyboardmunji
// Created on 2025-04-10.
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
string arr[1001];
pair<int,int> arr2[1001];
pair<int,int> arr3[1001];

bool comp(pair<int,int> a, pair<int,int> b) {
    if (a.X == b.X) {
        return a.Y > b.Y;
    }else
        return a.X < b.X;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기.
    cin >> n;
    for (int i =0;i<n;i++) cin >> arr[i];

    //랭크와 숫자 분리하기.
    for (int i = 0;i<n;i++) {
        if (arr[i][0] == 'B')
            arr2[i].X = 1;
        else if (arr[i][0] == 'S')
            arr2[i].X = 2;
        else if (arr[i][0] == 'G')
            arr2[i].X = 3;
        else if (arr[i][0] == 'P')
            arr2[i].X = 4;
        else
            arr2[i].X = 5;
        int len = arr[i].length(),num =0;
        for (int j = 1;j<len;j++) {
            int m = 1;
            for (int k = 1;k < len - j;k++) m*=10;
            num += (arr[i][j] - '0') * m;
        }
        arr3[i].Y = arr2[i].Y = num;
        arr3[i].X = arr2[i].X;
    }
    sort(arr2,arr2+n,comp);
    stack <string> ans;
    //잘못된 위치가 있는지 확인.
    for (int i= 0;i<n;i++)
        if (arr2[i].X != arr3[i].X || (arr3[i].X == arr2[i].X && arr2[i].Y != arr3[i].Y))
            ans.push(arr[i]);
    if (ans.empty()) {
        cout<<"OK";
    }else {
        cout <<"KO\n";
        cout << ans.top();
        ans.pop();
        cout <<" "<<ans.top();
    }
    return 0;
}

/*
 1.그냥 대소 관계를 정수로 치환한다음, sort해서 안맞는 것 2개가 답일듯.
*/

