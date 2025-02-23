//2533
#include <bits/stdc++.h>

int N;
std::vector<int> adj[1'000'001];

bool adopter[1'000'001];
bool vis[1'000'001];

void func(int cur) {
	vis[cur] = true;
	if (adj[cur].size() == 0) return; //리프 노드 도달시 중지

	for (int nxt : adj[cur]) {
		if(vis[nxt]) continue;

		func(nxt);
		if (!adopter[nxt]) adopter[cur] = true;
		//처음에는 리프 노드의 바로 전 노드가 얼리어답터, 그 이후부터는 자신의 다음 노드가 얼리어답터가 아닐 경우 자신이 얼리어답터
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	func(1);
	int cnt = 0;
	for (int i = 1; i <= N; i++) if (adopter[i]) cnt++;

	std::cout << cnt;
}