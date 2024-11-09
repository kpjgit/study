//1240
#include <bits/stdc++.h>

int N, M;
std::vector<std::pair<int, int>> adj_list[1001]; //다음 노드, 거리

bool vis[1001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int u, v, d;
    for(int i = 0; i < N - 1; i++) {
        std::cin >> u >> v >> d;
        adj_list[u].push_back({v, d});
        adj_list[v].push_back({u, d});
    }

    for(int num = 0; num < M; num++) {
        std::cin >> u >> v;

        std::fill(vis + 1, vis + N + 1, false);
        std::queue<std::pair<int, int>> q; //노드, 거리 합
        q.push({u, 0});
        vis[u] = true;

        while(!q.empty()) {
            int cur, dist;
            std::tie(cur, dist) = q.front();
            q.pop();

            if(cur == v) {
                std::cout << dist << '\n';
                break;
            }

            for(auto dir : adj_list[cur]) {
                if(vis[dir.first]) continue;
                
                vis[dir.first] = true;
                q.push({dir.first, dir.second + dist});
            }
        }
    }
}