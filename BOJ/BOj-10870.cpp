#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[21] = {0,1};
    for(int i=2;i<=20;i++)
        arr[i] = arr[i-1]+arr[i-2];
    int n;
    cin >> n;
    cout << arr[n];    
    return 0;
}
