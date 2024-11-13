//2623
#include <bits/stdc++.h>

int N, M;
std::vector<int> adj_list[1001]; //adj_list[i]의 i는 벡터에 포함된 가수보다 먼저 출연해야 한다
int indegree[1001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int num;
    int u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> num;
        if(num == 0) continue;

        std::cin >> u;
        for(int j = 1; j < num; j++) {
            std::cin >> v;
            adj_list[u].push_back(v);
            indegree[v]++;
            std::swap(u, v);
        }
    }

    std::vector<int> ans;
    std::queue<int> q;
    for(int i = 1; i <= N; i++) if(indegree[i] == 0) q.push(i);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int dir : adj_list[cur]) {
            indegree[dir]--;
            if(indegree[dir] == 0) q.push(dir); //사이클이 없다는 보장이 없으므로 ans의 크기가 N보다 작을 수 있다
        }
    }

    if(ans.size() != N) std::cout << 0;
    else for(int i : ans) std::cout << i << '\n';
}