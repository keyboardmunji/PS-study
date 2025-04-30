#include<iostream>
using namespace std;

int n,len;
string s;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    if(!cin.eof()){
        cin >> s;
        len = s.length();
    }    
    long long root = (1 << (n + 1)) - 1;
    long long node = 1;
    for(int i = 0; i<len;i++){
        if(s[i] == 'R')
            node = node * 2 + 1;
        else
            node = node * 2;
    }
    cout << root - node + 1;
    return 0;
}
