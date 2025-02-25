#include <iostream>
using namespace std;

int n, w, l,cnt; // truck_n: 다리를 건널 차례를 가르킴, truck_w : 다리위의 트럭의 무게, bridge_n : 다리위 트럭 개수
int truck_n,truck_w,bridge_n; // truck[1001] : 트럭의 무게 정보를 담음.
int truck[1001];
int truck_t[1001]; // 현재 트럭이 다리 기준 어느정도 움직였는지 확인

int main(void)
{
	cin >> n >> w >> l;
	for (int i = 0;i < n;i++) cin >> truck[i];
	while (truck_t[n-1] != w)
	{
		if (bridge_n < w && truck_w + truck[truck_n] <= l)
		{
			truck_w += truck[truck_n];
			truck_n++;
			bridge_n++;
		}
		for (int i = 0;i < truck_n;i++)
		{
			if (truck_t[i] < w)
			{
				truck_t[i]++;
				if (truck_t[i] == w)
				{
					truck_w -= truck[i];
					bridge_n--;
				}
			}
		}
		cnt++;
	}
	cout << cnt + 1;
	return 0;
}
