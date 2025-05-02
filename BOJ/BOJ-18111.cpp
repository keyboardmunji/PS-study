#include<iostream>

using namespace std;

int n,m,b,ans=2000000000,layer;
int mp[501][501];
int cp[501][501];
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>> n>> m >> b;
    for(int i = 0; i<n;i++)
        for(int j = 0; j<m;j++)
            cin >> mp[i][j];
    for(int i = 0; i<= 256;i++){
        int cnt = 0,bl = b;
        for(int j = 0; j < n; j ++){
            for(int k =0; k<m;k++){
                int th = mp[j][k] - i;
                if(th >= 0) {
                    cnt += 2*th;
                    bl += th;
                }else{
                    cnt += th * -1;
                    bl += th;
                }
            }
        }         
        if(ans>=cnt && bl >= 0){
            ans = cnt;
            layer = i;
        }
    }
    cout << ans << " "<< layer;
    return 0;
}
