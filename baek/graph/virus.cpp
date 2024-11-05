//2606
#include <bits/stdc++.h>

int N, M;
std::vector<int> adj_list[101];
bool vis[101];

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
    std::queue<int> q;
    vis[1] = true;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int dir : adj_list[cur]) {
            if(vis[dir] == true) continue;

            vis[dir] = true;
            q.push(dir);
            ans++;
        }
    }

    std::cout << ans;
}