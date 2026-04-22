#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n, m;
std::vector<int> adj[101];

int dist[101];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
    int t1, t2;
    std::cin >> n >> t1 >> t2 >> m;
    
    int x, y;
    for(int i = 0; i < m; i++) {
        std::cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    
    std::fill(dist + 1, dist + n + 1, -1);
    std::queue<int> q;
    q.push(t1);
    dist[t1] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int nxt : adj[cur]) {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    std::cout << dist[t2];
}