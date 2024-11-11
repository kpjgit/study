//2252
#include <bits/stdc++.h>

int N, M;
std::vector<int> adj_list[32001]; //adj_list[i]일때 학생 i는 벡터에 속하는 학생보다 키가 작다
int indegree[32001];

std::vector<int> ans;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    int A, B;
    for(int i = 0; i < M; i++) {
        std::cin >> A >> B;
        adj_list[A].push_back(B);
        indegree[B]++;
    }

    std::queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int dir : adj_list[cur]) {
            indegree[dir]--;
            if(indegree[dir] == 0) q.push(dir);
        }
    }
    
    for(int i : ans) std::cout << i << ' ';
}