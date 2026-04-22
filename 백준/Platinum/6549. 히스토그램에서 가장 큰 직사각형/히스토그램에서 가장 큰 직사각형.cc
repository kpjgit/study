#include <bits/stdc++.h>
//스택 풀이

int n;
long long arr[100000];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	//스택을 항상 오름차순으로 유지한다
	//스택에 인덱스 정보도 포함하여 끝에 도달하거나 오름차순을 유지하지 못 할때 i - idx로 너비 계산이 가능하다
	std::stack<std::pair<int, long long>> s;
	long long ans;
	while (true) {
		ans = 0;
		std::cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) std::cin >> arr[i];
		
		for (int i = 0; i < n; i++) {
			int st = i;
			while (!s.empty() && s.top().second > arr[i]) {
				ans = std::max(ans, (i - s.top().first) * s.top().second);
				st = s.top().first;
				s.pop();
			}

			s.push({ st, arr[i] });
		}

		while (!s.empty()) {
			ans = std::max(ans, (n - s.top().first) * s.top().second);
			s.pop();
		}

		std::cout << ans << '\n';
	}
}