#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N, M, K, X;
std::vector<int> adj[300001];

int dist[300001];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M >> K >> X;
    int u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    
    std::fill(dist + 1, dist + N + 1, -1);
    std::queue<int> q;
    q.push(X);
    dist[X] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int nxt : adj[cur]) {
            if(dist[nxt] != -1) continue;
            
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    std::vector<int> ans;
    for(int i = 1; i <= N; i++) if(dist[i] == K) ans.push_back(i);
    std::sort(ans.begin(), ans.end());
    for(int a : ans) std::cout << a << '\n';
    if(ans.size() == 0) std::cout << -1;
}