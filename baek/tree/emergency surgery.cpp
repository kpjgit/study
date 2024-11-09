//20955
#include <bits/stdc++.h>

int N, M;
int u, v;
std::vector<int> adj_list[100001];

bool vis[100001];

void bfs(int x) {
    std::queue<int> q;
    q.push(x);
    vis[x] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir : adj_list[cur]) {
            if(vis[dir]) continue;

            vis[dir] = true;
            q.push(dir);
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int num_tree = 0;
    for(int i = 1; i <= N; i++) {
        if(vis[i]) continue;
        bfs(i);
        num_tree++;
    }

    int con = num_tree - 1; //어떤 트리의 루트와 다른 트리의 리프를 연결
    int cut = M + num_tree - 1 - (N - 1); //트리의 간선 갯수는 N-1이 되어야 하니 전체 간선 갯수에서 N-1을 뺌
    std::cout << con + cut;
}