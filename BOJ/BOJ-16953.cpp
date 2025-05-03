#include<iostream>
#include <queue>
using namespace std;

int a,b;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b;
    queue<pair<long long,int>> q;
    q.push({a,1});
    while(!q.empty()){
        auto c = q.front(); q.pop();
        if(c.first == b){
            cout << c.second;
            return 0;
        }
        if(c.first*2 <= b) q.push({c.first*2,c.second + 1});
        if(c.first*10 + 1 <= b) q.push({c.first*10 + 1,c.second + 1});
    }
    cout << -1;
    return 0;
}
