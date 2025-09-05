#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,p,q;
map <ll, ll> m;

ll dp(ll i) {
    if (i == 0)
        return 1;
    ll x = m[i/p],y = m[i/q];
    if (x == 0)
        m[i/p] = x = dp(i/p);
    if (y == 0)
        m[i/q] = y = dp(i/q);

    return x + y;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p >> q;
    cout << dp(n);

    return 0;
}

/*

*/