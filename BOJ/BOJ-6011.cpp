#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int n,cnt;
pair<int,int> arr[50001];
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n;i++) cin >> arr[i].X >> arr[i].Y;
    sort(arr,arr+n);
    
    int en = 0;
    for(int i = 0; i<n;i++){
        if(en <= arr[i].X){
            cnt++;
            en = arr[i].Y;
        }else if(en > arr[i].Y){
            en = arr[i].Y;
        }
    }
    cout << cnt;
    return 0;
}
