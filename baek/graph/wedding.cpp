//5567
#include <bits/stdc++.h>

int n, m;
std::vector<int> adj_list[501];
int dist[501];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        std::cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    std::fill(dist + 1, dist + n + 1, -1);

    int ans = 0;
    std::queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir : adj_list[cur]) {
            if(dist[dir] >= 0) continue;

            dist[dir] = dist[cur] + 1;
            if(dist[dir] <= 2) ans++;
            if(dist[dir] <= 1) q.push(dir);
        }
    }

    std::cout << ans;
}