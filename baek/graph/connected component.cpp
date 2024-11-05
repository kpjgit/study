//11724
#include <bits/stdc++.h>

int N, M;
std::vector<int> adj_list[1001];
bool vis[1001];

void bfs(int u){
    vis[u] = true;
    std::queue<int> q;
    q.push(u);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir : adj_list[cur]) {
            if(vis[dir] == true) continue;

            vis[dir] = true;
            q.push(dir);
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(vis[i] == true) continue;

        bfs(i);
        ans++;
    }
    
    std::cout << ans;
}