#include <bits/stdc++.h>

int N;
std::pair<long long, int> arr[100000]; //무게, 원래 idx
//처음 상태와 정렬된 상태를 비교해 값의 위치가 달라지면 그 값은 사이클에 포함이 된다.
//사이클 안의 최소값을 활용해 정렬하는 것이 최소값을 보장한다
//배열 전체의 최소가 사이클 밖에 있을 경우 그 값을 사이클에 포함시켰다 되돌리는 것이 최소 후보가 될 수 있다

bool vis[100000];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i].first;
		arr[i].second = i;
	}
	std::sort(arr, arr + N);

	long long mn_arr = arr[0].first; //정렬 했으므로 가장 앞에 최소값이있다
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;

		long long cycle_cost = 0;
		int cycle_length = 0;
		long long mn_cycle = arr[i].first; //정렬을 하고 vis에 의해 앞 원소는 접근이 안 되니 i가 사이클 안에서의 최소값
		int cursor = i;
		while (!vis[cursor]) {
			vis[cursor] = true;
			cycle_cost += arr[cursor].first;
			cycle_length++;
			cursor = arr[cursor].second;
		} //사이클을 기준으로 배열을 원상복귀 하는 과정은 배열을 정렬하는 과정의 역순이다

		long long cost_in_cycle = mn_cycle * (cycle_length - 2);
		long long cost_out_cycle = mn_arr * (cycle_length + 1) + mn_cycle;

		ans += std::min(cost_in_cycle, cost_out_cycle) + cycle_cost;
	}

	std::cout << ans;
}