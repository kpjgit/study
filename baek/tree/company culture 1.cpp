//14267
#include <bits/stdc++.h>

int n, m;
std::vector<int> adj_list[100001];
int par[100001];

int ans[100001];

void bfs() {
    std::queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir : adj_list[cur]) {
            if(dir == par[cur]) continue;

            ans[dir] += ans[cur];
            q.push(dir);
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::cin >> par[i];
        if(par[i] == -1) continue;
        adj_list[par[i]].push_back(i);
    }

    int x, val;
    for(int i = 0; i < m; i++) {
        std::cin >> x >> val;
        ans[x] += val;
    }

    bfs();

    for(int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
}