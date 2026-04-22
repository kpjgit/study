#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

int V, E, K;
std::vector<std::pair<int, int>> adj[20001];

const int mx_cost = 3000001;
int dist[20001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> V >> E >> K;
    int u, v, w;
    std::fill(dist, dist + V + 1, mx_cost);
    for(int i = 0; i < E; i++) {
        std::cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    dist[K] = 0;
    pq.push({0, K});
    while(!pq.empty()) {
        int cur, cost;
        std::tie(cost, cur) = pq.top();
        pq.pop();
        if(dist[cur] != cost) continue;
        
        for(auto& nxt : adj[cur]) {
            int nxt_cost = nxt.first + dist[cur];
            if(nxt_cost >= dist[nxt.second]) continue;
            
            dist[nxt.second] = nxt_cost;
            pq.push({nxt_cost, nxt.second});
        }
    }
    
    for(int i = 1; i < V + 1; i++) {
        if(dist[i] == mx_cost) std::cout << "INF\n";
        else std::cout << dist[i] << '\n';
    }
}