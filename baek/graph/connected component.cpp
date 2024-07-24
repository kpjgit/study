//11724
#include <bits/stdc++.h>

int n, m;
std::vector<int> adj_list[1001];
bool vis[1001];
int ans;

void bfs() {
    std::queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == true) continue;
        q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto e : adj_list[cur]) {
                if(vis[e] == true) continue;
                q.push(e);
                vis[e] = true;
            }
        }
        ans++;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs();

    std::cout << ans;
}