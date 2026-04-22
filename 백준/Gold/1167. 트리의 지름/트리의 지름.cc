#include <iostream>
#include <vector>
#include <algorithm>

int V;
std::vector<std::pair<int, int>> adj[100001]; //nxt, cost

bool vis[100001];
int ans;
int func(int node, int nxt_cost) {
	int cur_cost = nxt_cost;
	int longest = 0;

	vis[node] = true;
	for (auto nxt : adj[node]) {
		if (vis[nxt.first]) continue;

		int candidate = func(nxt.first, nxt.second);
		ans = std::max(ans, longest + candidate);
		longest = std::max(longest, candidate);
	}

	return longest + cur_cost;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> V;
	int u, v, cost;
	int root;
	for (int i = 0; i < V; i++) {
		std::cin >> u;
		root = u; //1번 노드가 항상 있다는 보장이 없음
		while (true) {
			std::cin >> v;
			if (v == -1) break;

			std::cin >> cost;
			adj[u].push_back({ v, cost });
		}
	}

	func(root, 0);
	std::cout << ans;
}