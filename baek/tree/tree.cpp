//4803
#include <bits/stdc++.h>

int n, m;
std::vector<int> adj_list[501];

bool vis[501];

bool bfs(int root) {
    std::queue<std::pair<int, int>> q; //노드, 부모
    vis[root] = true;
    q.push({root, 0});

    bool result = true;

    while(!q.empty()) {
        int cur, par;
        std::tie(cur, par) = q.front();
        q.pop();

        for(int dir : adj_list[cur]) {
            if(dir == par) continue;
            if(vis[dir]) { //부모가 아니면서 이미 방문한 노드에 방문하는게 가능하면 사이클이 있음
                result = false;
                continue;
            }

            vis[dir] = true;
            q.push({dir, cur});
        }
    }

    return result;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int u, v;
    for(int casenum = 1; ; casenum++) {
        std::cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i < m; i++) {
            std::cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        int cnt = 0;
        std::fill(vis + 1, vis + n + 1, false);
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;

            cnt += bfs(i);
        }

        if(cnt == 0) std::cout << "Case " << casenum << ": No trees.\n";
        else if(cnt == 1)  std::cout << "Case " << casenum << ": There is one tree.\n";
        else  std::cout << "Case " << casenum << ": A forest of "<< cnt <<" trees.\n";

        for(int i = 1; i <= n; i++) adj_list[i].clear();
    }
}