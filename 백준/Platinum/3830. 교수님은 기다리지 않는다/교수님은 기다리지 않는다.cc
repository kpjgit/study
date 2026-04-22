#include <iostream>
#include <algorithm>

int N, M;

int p[100001];
int w[100001]; //i에서부터 루트 까지의 거리, 누적된 가중치와 동의어

int find(int x) {
	if (p[x] < 0) return x;

	int par = p[x];
	int root = find(par);
	w[x] += w[par]; // 경로 압축에 포함됨, 이미 압축되어 par이 루트일 경우 w[par]은 0
	return p[x] = root;
}

bool uni(int u, int v, int diff) {
	int root_u = find(u);
	int root_v = find(v);

	if (root_u == root_v) return false;

	if (p[root_v] < p[root_u]) {
		std::swap(u, v);
		std::swap(root_u, root_v);
		diff = -diff;
	}

	if (p[root_u] == p[root_v]) p[root_u]--;

	p[root_v] = root_u;
	w[root_v] = w[u] - w[v] + diff; //이제는 루트가 아닌 root_v에서부터 루트까지의 거리 갱신

	return true;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	char op;
	int u, v, diff;
	while (true) {
		std::cin >> N >> M;
		if (N == 0) break;

		std::fill(p, p + N + 1, -1);
		std::fill(w, w + N + 1, 0);

		for (int i = 0; i < M; i++) {
			std::cin >> op;
			if (op == '!') {
				std::cin >> u >> v >> diff;
				uni(u, v, diff);
			}
			else {
				std::cin >> u >> v;
				if (find(u) != find(v)) std::cout << "UNKNOWN\n";
				else std::cout << w[v] - w[u] << '\n';
			}
		}
	}
}