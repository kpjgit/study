//1647
#include <bits/stdc++.h>

int N, M;
std::vector<std::pair<int, int>> adj_list[100001]; //비용, 집

bool vis[100001];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int u, v, cost;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v >> cost;
        adj_list[u].push_back({cost, v});
        adj_list[v].push_back({cost, u});
    }

    vis[1] = true;
    for(auto& road : adj_list[1]) pq.push(road);

    int mx_cost = 0; //최소 신장 트리를 구한 후 길 하나를 없애면 마을이 두개로 나뉜다
    int cnt = 0;
    int ans = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(vis[cur.second]) continue;

        vis[cur.second] = true;
        ans += cur.first;
        cnt++;
        mx_cost = std::max(mx_cost, cur.first);
        if(cnt == N - 1) break;

        for(auto& road : adj_list[cur.second]) if(!vis[road.second]) pq.push(road);
    }

    std::cout << ans - mx_cost;
}