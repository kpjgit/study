//2617
#include <bits/stdc++.h>

int N, M;
std::vector<int> heavy[100], light[100]; //a가 b보다 무겁고 b가 c보다 무겁다면 a는 c보다 무겁다, 그래프 탐색

bool vis[100];

bool bfs(int n, const std::vector<int> *graph) {
    std::fill(vis + 1, vis + N + 1, false);
    
    std::queue<int> q;
    q.push(n);
    vis[n] = true;
    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir : graph[cur]) {
            if(vis[dir]) continue;

            vis[dir] = true;
            q.push(dir);
            cnt++;
        }
    }

    return cnt >= (N + 1) / 2; //과반에 대해 무겁거나 가벼우면 중간값이 될 수 없음
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        heavy[u].push_back(v);
        light[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) ans += (bfs(i, heavy) || bfs(i, light));

    std::cout << ans;
}