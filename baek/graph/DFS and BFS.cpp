//1260
#include <bits/stdc++.h>

int n, m, st;
std::vector<int> adj_list[1001];
bool vis[1001];

void bfs() {
    std::queue<int> q;
    q.push(st);
    vis[st] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        for(auto e : adj_list[cur]) {
            if(vis[e] == true) continue;
            q.push(e);
            vis[e] = true;
        }
    }
}

void dfs(int cur) {
    vis[cur] = true;
    std::cout << cur << ' ';
    for(auto e : adj_list[cur]) {
        if(vis[e] == true) continue;
        dfs(e);
    }
}

void dfs_not_recursive() {
    std::stack<int> s;
    s.push(st);
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        if(vis[cur] == true) continue;
        vis[cur] = true;
        std::cout << cur << ' ';
        for(int i = adj_list[cur].size() - 1; i > 0; i--) {
            int next = adj_list[cur][i];
            s.push(next);
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> st;
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        std::sort(adj_list[i].begin(), adj_list[i].end());
    }

    //dfs(st);
    dfs_not_recursive();
    std::cout << '\n';
    std::fill(vis + 1, vis + n + 1, false);
    bfs();
}