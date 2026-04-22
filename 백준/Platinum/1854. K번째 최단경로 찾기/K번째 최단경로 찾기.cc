#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

int n, m, k;
std::vector<std::pair<long long, int>> adj[1001];

std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq; //cost, node
std::priority_queue<long long> candidate[1001];

int main(void) {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, cost;
        std::cin >> u >> v >> cost;
        adj[u].push_back({cost, v});
    }
    
    //다익스트라는 최소 경로일 경우 부분 최적을 갱신하는 방식
    //다익스트라를 사용하되 갱신한 내역을 기록하도록 한다
    candidate[1].push(0);
    pq.push({0, 1});
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        for(auto nxt : adj[cur.second]) {
            long long nxt_cost = cur.first + nxt.first;
            
            if(candidate[nxt.second].size() < k) {
                candidate[nxt.second].push(nxt_cost);
                pq.push({nxt_cost, nxt.second});
            } else if(nxt_cost < candidate[nxt.second].top()) {
                candidate[nxt.second].pop();
                candidate[nxt.second].push(nxt_cost);
                pq.push({nxt_cost, nxt.second});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(candidate[i].size() < k) {
            std::cout << -1 << '\n';
        } else {
            std::cout << candidate[i].top() << '\n';
        }
    }
}