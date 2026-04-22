#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

int N, M;
//cost, node
std::vector<std::pair<int, int>> adj[1001];

long long dist[1001];

const long long mx_dist = (long long)100000 * 100000 + 1;

int main(void) {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> M;
    int st, en, cost;
    for(int i = 0; i < M; i++) {
        std::cin >> st >> en >> cost;
        adj[st].push_back({cost, en});
    }
    std::fill(dist, dist + N + 1, mx_dist);
    
    std::cin >> st >> en;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    while(!pq.empty()) {
        int cur;
        long long cost;
        std::tie(cost, cur) = pq.top();
        pq.pop();
        if(cost != dist[cur]) continue;
        
        for(auto& nxt : adj[cur]) {
            long long nxt_cost = nxt.first + cost;
            if(nxt_cost >= dist[nxt.second]) continue;
            dist[nxt.second] = nxt_cost;
            pq.push({dist[nxt.second], nxt.second});
        }
    }
    
    std::cout << dist[en];
}