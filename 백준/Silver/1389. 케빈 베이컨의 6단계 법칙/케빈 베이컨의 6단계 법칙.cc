#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

int N, M;
std::vector<int> adj[101];

std::unordered_set<int> did[101];
int dist[101];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M;
    int u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        
        if(did[u].find(v) != did[u].end()) continue;
        
        adj[u].push_back(v);
        did[u].insert(v);
        adj[v].push_back(u);
        did[v].insert(u);
    }
    
    int ans = -1;
    int cnt = 10001;
    for(int i = 1; i <= N; i++) {
        std::fill(dist + 1, dist + N + 1, -1);
        std::queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int nxt : adj[cur]) {
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
        
        int sum = 0;
        for(int j = 1; j <= N; j++) {
            //if(dist[j] == -1) continue;
            sum += dist[j];
        }
        
        if(sum < cnt) {
            ans = i;
            cnt = sum;
        }
    }
    
    std::cout << ans;
}