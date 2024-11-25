//10423
#include <bits/stdc++.h>

int N, M, K;
std::vector<std::pair<int, int>> adj_list[1001]; //비용, 도시
std::vector<int> generator;

bool vis[1001];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> K;
    int u, v, w;
    for(int i = 0; i < K; i++) {
        std::cin >> u;
        generator.push_back(u);
    }

    for(int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
        adj_list[v].push_back({w, u});
    }

    for(int i : generator) { //최소힙에 K개의 시작점을 넣으면 도시가 K개로 분리된다
        vis[i] = true;
        for(auto& line : adj_list[i]) pq.push(line);
    }

    int ans = 0;
    int cnt = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(vis[cur.second]) continue;

        vis[cur.second] = true;
        ans += cur.first;
        cnt++;
        if(cnt == N - K) break;

        for(auto& line : adj_list[cur.second]) if(!vis[line.second]) pq.push(line);
    }

    std::cout << ans;
}