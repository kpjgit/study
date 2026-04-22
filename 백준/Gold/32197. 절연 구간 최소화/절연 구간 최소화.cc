#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int N, M;
std::vector<std::pair<bool, int>> vec[100001];

int mx = 1e9;
int dist[2][100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M;
    int u, v, c;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v >> c;
        vec[u].push_back({c, v});
        vec[v].push_back({c, u});
    }
    std::cin >> u >> v;
    
    if(u == v) {
        std::cout << 0;
        return 0;
    }
    
    std::fill(dist[0], dist[0] + N + 1, mx);
    std::fill(dist[1], dist[1] + N + 1, mx);
    //cost, node, prev
    std::priority_queue<std::tuple<int ,int, bool>, std::vector<std::tuple<int, int, bool>>, std::greater<std::tuple<int, int, bool>>> pq;
    for(auto& i : vec[u]) {
        dist[i.first][i.second] = 0;
        pq.push({0, i.second, i.first});
    }
    while(!pq.empty()) {
        int cost, cur, prev;
        std::tie(cost, cur, prev) = pq.top();
        pq.pop();
        if(dist[prev][cur] != cost) continue;
        
        for(auto& nxt : vec[cur]) {
            int cost_new = cost + (nxt.first != prev);
            
            if(dist[nxt.first][nxt.second] <= cost) continue;
            
            dist[nxt.first][nxt.second] = cost_new;
            pq.push({cost_new, nxt.second, nxt.first});
        }
    }
    
    std::cout << std::min(dist[0][v], dist[1][v]);
}