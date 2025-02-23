//2887
#include <bits/stdc++.h>

int N;
std::pair<int, int> coord_x[100000]; //좌표, 행성
std::pair<int, int> coord_y[100000]; 
std::pair<int, int> coord_z[100000];
//시간 제한 때문에 100000*100000개의 경로를 모두 만들 수는 없으므로 x y z 좌표에 대해 정렬하고 인접한 경로만 계산한다

std::vector<std::tuple<int, int, int>> vec; //가중치, 행성, 행성
int p[300000];

int find(int x) {
	if (p[x] < 0) return x;

	return p[x] = find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	if (p[v] < p[u]) std::swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;

	return true;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> N;
	int x, y, z;
	for (int i = 0; i < N; i++) {
		std::cin >> x >> y >> z;
		coord_x[i] = { x, i };
		coord_y[i] = { y, i };
		coord_z[i] = { z, i };
	}
	std::sort(coord_x, coord_x + N);
	std::sort(coord_y, coord_y + N);
	std::sort(coord_z, coord_z + N);

	auto prev = coord_x[0];
	for (int i = 1; i < N; i++) {
		auto cur = coord_x[i];
		vec.push_back({ cur.first - prev.first, cur.second, prev.second });
		std::swap(prev, cur);
	}

	prev = coord_y[0];
	for (int i = 1; i < N; i++) {
		auto cur = coord_y[i];
		vec.push_back({ cur.first - prev.first, cur.second, prev.second });
		std::swap(prev, cur);
	}

	prev = coord_z[0];
	for (int i = 1; i < N; i++) {
		auto cur = coord_z[i];
		vec.push_back({ cur.first - prev.first, cur.second, prev.second });
		std::swap(prev, cur);
	}

	int ans = 0;
	int cnt = 0;
	std::sort(vec.begin(), vec.end());
	std::fill(p, p + 3 * N, -1);
	for (int i = 0; i < vec.size(); i++) {
		int u, v, cost;
		std::tie(cost, u, v) = vec[i];

		if (!uni(u, v)) continue;

		ans += cost;
		cnt++;
		if (cnt == N - 1) break;
	}

	std::cout << ans;
}