// Authored by : keyboardmunji
#include <bits/stdc++.h>

using namespace std;

int n,l,cnt = 0;
int arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;
    for (int i =0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    int i = 0,len = 0;
    while (i < n) {
        if (len < arr[i]) {
            cnt += 1;
            len = arr[i] + l - 1;
        }
        i++;
    }
    cout << cnt;
    return 0;
}

/*
예를 들면 1을 막으려면 0.5~ 1.5까지 테이프를 이용하는 것 같다.
테이프를 겹쳐서 써도 된다는 건 그냥 무시해도 될듯. 다른 경우를 생각하지 못하도록 막는 장치인듯
또한 무조건 세는 파이프를 막아야 해서, 간단함.

따라서 방식은 다음 과 같다.
1. 입력 받은 배열을 sort해준다.
2. 처음에 세는 곳을 m, 테이프의 길이를 l이라 하면, 최대 m~m + l -1 까지 막을 수 있다.
3. 따라서 막을 수 있으면 pass 못막으면 다시 m+l-1을 갱신해주는 방식으로 cnt를 세면 될듯.
*/