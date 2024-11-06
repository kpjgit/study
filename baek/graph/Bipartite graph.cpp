//1707
#include <bits/stdc++.h>

int K, V, E;
std::vector<int> adj_list[20001];

int vis[20001];

bool bfs(int x) {
    std::queue<int> q;
    vis[x] = 0;
    q.push(x);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int nxt = 1 - vis[cur];

        for(int dir : adj_list[cur]) {
            if(vis[dir] == vis[cur]) return false; //방문한 노드에 0과 1을 남기고 인접한 노드의 vis가 같을 경우 불가능
            if(vis[dir] != -1) continue;

            vis[dir] = nxt;
            q.push(dir);
        }
    }

    return true;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> K;
    int u, v;
    for(int num = 0; num < K; num++) {
        std::cin >> V >> E;
        for(int i = 0; i < E; i++) {
            std::cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        std::fill(vis + 1, vis + V + 1, -1);
        bool chk = true;
        for(int i = 1; i <= V; i++) {
            if(vis[i] != -1) continue;

            if(!bfs(i))  {
                chk = false;
                break;
            }
        }

        if(chk) std::cout << "YES\n";
        else std::cout<< "NO\n";
        
        for(int i = 1; i <= V; i++) adj_list[i].clear();
    }
}