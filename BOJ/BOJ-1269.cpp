// Authored by : keyboardmunji
// Created on 2025-04-27.
#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
int arr[200001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    for (int i =0;i<m;i++) {
        int x;
        cin >> x;
        if (binary_search(arr,arr+n,x))
            a++; // a => 교집합 개수
    }
    cout << n + m - a*2 ;

    return 0;
}
/*
1.binary_search의 시간복잡도는 (logn)임.
2. n이 20만이하라 nlogn으로 처리가능
-> 방식 : a를 받은 뒤 소트, 그 후 b의 원소를  계속 받으면서, bianry_search가 true인지 확인.
*/