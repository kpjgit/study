//13418
#include <bits/stdc++.h>

int N, M;
std::vector<std::pair<int, int>> adj_list[1001]; //비용, 연결된 건물

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq_best;
std::priority_queue<std::pair<int, int>> pq_worst;
bool vis[1001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int u, v;
    bool cost;
    for(int i = 0; i < M + 1; i++) {
        std::cin >> u >> v >> cost;

        adj_list[u].push_back({!cost, v});
        adj_list[v].push_back({!cost, u});
    }

    vis[0] = true;
    for(auto& road : adj_list[0]) pq_best.push(road);
    int cnt = 0;
    int ans_best = 0;
    while(!pq_best.empty()) {
        auto cur = pq_best.top();
        pq_best.pop();
        if(vis[cur.second]) continue;

        vis[cur.second] = true;
        cnt++;
        ans_best += cur.first;
        if(cnt == N) break;

        for(auto& road : adj_list[cur.second]) if(!vis[road.second]) pq_best.push(road);
    }

    std::fill(vis, vis + N + 1, false);
    vis[0] = true;
    for(auto& road : adj_list[0]) pq_worst.push(road);
    cnt = 0;
    int ans_worst = 0;
    while(!pq_worst.empty()) {
        auto cur = pq_worst.top();
        pq_worst.pop();
        if(vis[cur.second]) continue;

        vis[cur.second] = true;
        cnt++;
        ans_worst += cur.first;
        if(cnt == N) break;

        for(auto& road : adj_list[cur.second]) if(!vis[road.second]) pq_worst.push(road);
    }

    std::cout << ans_worst * ans_worst - ans_best * ans_best;
} 