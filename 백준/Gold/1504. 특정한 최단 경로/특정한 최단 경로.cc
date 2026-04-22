#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

int N, E;
std::vector<std::pair<int, int>> adj[801];

const int mx_cost = 800 * 1000 * 3 + 1;
int dist[801];

void func(int x) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    
    std::fill(dist + 1, dist + N + 1, mx_cost);
    dist[x] = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        int cur, cost;
        std::tie(cost, cur) = pq.top();
        pq.pop();
        
        if(cost != dist[cur]) continue;
        
        for(auto nxt : adj[cur]) {
            int cost_n = nxt.first + cost;
            if(cost_n >= dist[nxt.second]) continue;
            
            dist[nxt.second] = cost_n;
            pq.push({cost_n, nxt.second});
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> E;
    int u, v, cost;
    for(int i = 0; i < E; i++) {
        std::cin >> u >> v >> cost;
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }
    
    std::cin >> u >> v;
    
    //양방향 그래프라서 두번만
    //최단 경로의 부분은 항상 최적, 귀류법
    func(u);
    int one_to_v1 = dist[1];
    int v1_to_v2 = dist[v]; //v1, v2 공용
    int v1_to_N = dist[N];
    func(v);
    int one_to_v2 = dist[1];
    int v2_to_N = dist[N];
    
    int ans1 = one_to_v1 + v1_to_v2 + v2_to_N;
    int ans2 = one_to_v2 + v1_to_v2 + v1_to_N;
    int ans = std::min(ans1, ans2);
    if(ans >= mx_cost) std::cout << -1;
    else std::cout << ans;
}