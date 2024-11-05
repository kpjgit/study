//1260
#include <bits/stdc++.h>

int N, M, V;
std::vector<int> adj_list[1001];
bool vis[1001];

void bfs() {
    std::queue<int> q;
    vis[V] = true;
    q.push(V);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        
        for(int dir : adj_list[cur]) {
            if(vis[dir] == true) continue;

            q.push(dir);
            vis[dir] = true;
        }
    }
}

void dfs(int cur) {
    vis[cur] = true;
    std::cout << cur << ' ';

    for(int dir : adj_list[cur]) {
        if(vis[dir] == true) continue;
        dfs(dir);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> V;
    int u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for(int i = 1; i <= N; i++) std::sort(adj_list[i].begin(), adj_list[i].end());

    dfs(V);
    std::cout << '\n';

    std::fill(vis + 1, vis + N + 1, false);
    bfs();
}