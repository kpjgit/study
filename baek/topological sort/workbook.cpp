//1766
#include <bits/stdc++.h>

int N, M;
std::vector<int> adj_list[32001];

int indegree[32001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        indegree[v]++;
    }

    std::vector<int> ans;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; //진입차수가 0이면서 가장 쉬운 문제
    for(int i = 1; i <= N; i++) if(indegree[i] == 0) pq.push(i);

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);

        for(int dir : adj_list[cur]) {
            indegree[dir]--;
            if(indegree[dir] == 0) pq.push(dir);
        }
    }

    for(int i : ans) std::cout << i << ' ';
}