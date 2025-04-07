#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;

    while (++t) {
        int l, p, v;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) break;
        cout << "Case " << t << ": " << l*(v / p) + min(v % p, l) << '\n';
    }

    return 0;
}
/*
1. l일중 p일동안 사용가능하다. 따라서 p일이 주어진다면 l일동안 가야할 것이다.
2. 그렇다면 v = p+1이라면 어떻게 될까.
   당연하게 l+1일동안 사용할 것이다.
   조금 더 분석해보면 l = 3, p = 4, v = 5라고 해보자.
   OOOXO로 캠핑을 떠달 것인데, 이유는 p + 1일째에 1번째날이 p의 연속성에 포함되지 않는다.
   따라서 p + n번째에 갈지 말지는 n일에 갔는지 안갔는지와 같다는 뜻이다.
   (문제와는 상관없지만 일반화하면 이러하다.)
3. 따라서 최대일수는 l*(v / p) + min(v%p,l)일것이다.
*/