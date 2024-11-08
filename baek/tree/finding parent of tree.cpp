//11725
#include <bits/stdc++.h>

int N;
std::vector<int> adj_list[100001];

int par[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int u, v;
    for(int i = 1; i < N; i++) {
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    std::queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir : adj_list[cur]) {
            if(dir == par[cur]) continue;
            
            par[dir] = cur;
            q.push(dir);
        }
    }

    for(int i = 2; i <= N; i++) std::cout << par[i] << '\n';
}