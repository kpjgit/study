//1774
#include <bits/stdc++.h>

int N, M;
std::pair<int, int> coordinate[1001]; //1번은 황선자씨의 좌표
std::unordered_set<int> connected[1001];

std::vector<std::pair<long long, int>> adj_list[1001]; //비용, 우주신
std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
bool vis[1001];

int main(void) {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        std::cin >> coordinate[i].first >> coordinate[i].second;
    }

    int u, v;
    for(int i = 0; i < M; i++) { //이미 연결된 통로, 비용이 0
        std::cin >> u >> v;
        connected[u].insert(v);
        connected[v].insert(u);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(connected[i].find(j) != connected[i].end()) {
                adj_list[i].push_back({0, j});
                adj_list[j].push_back({0, i});
                continue;
            }

            int dx = coordinate[i].first - coordinate[j].first;
            int dy = coordinate[i].second - coordinate[j].second;
            long long cost = static_cast<long long>(dx) * dx + static_cast<long long>(dy) * dy;
            
            adj_list[i].push_back({cost, j});
            adj_list[j].push_back({cost, i});
        }
    }

    double ans = 0;
    int cnt = 0;
    vis[1] = true;
    for(auto& road : adj_list[1]) pq.push(road);
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(vis[cur.second]) continue;

        vis[cur.second] = true;
        cnt++;
        ans += std::sqrt(cur.first);
        if(cnt == N - 1) break;

        for(auto& road : adj_list[cur.second]) if(!vis[road.second]) pq.push(road);
    }

    std::cout << std::fixed << std::setprecision(2) << ans;
}