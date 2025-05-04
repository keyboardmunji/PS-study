#include<iostream>
#include<unordered_map>
using namespace std;

int n,m,cnt;
unordered_map <string,bool> s;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0 ; i<n;i++){
        string a;
        cin >> a;
        s[a] = true;
    }
    for(int j=0;j<m;j++){
        string a;
        cin >> a;
        if(s.count(a))
            cnt++;
    }
    cout << cnt;
    return 0;
}
