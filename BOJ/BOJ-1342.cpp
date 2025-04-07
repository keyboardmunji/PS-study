#include <bits/stdc++.h>

using namespace std;

string s;
int arr[26];
int cnt, len;

void func1(int num, char ex){
    if (num == len)
        cnt++;
    else {
        for (int i = 0;i < 26;i++) {
            if (!arr[i] || ex == char(i+'a')) continue;
            arr[i]--;
            func1(num + 1, char(i + 'a'));
            arr[i]++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    len = s.length();
    for (int i = 0;i < len;i++)
        arr[s[i] - 'a']++;
    func1(0, '\0');
    cout << cnt;
    return 0;
}
/*
1. 백트래킹으로 생각.
2. 10! = 10 * 10 * 9 * 8 * 7 * 8 * 9
       = 10^7이라고 생각, 대략 1천만
    흠,, 되겠는데?
*/